<?php
//require_once 'historique_releves.php';

//**********  Fonction recupére et affiche le dernier relevé effectué ********** 

function dernier_releve(){
    
    require 'connexion.php';    
    // on va chercher la derniere entrée dans la table des relevés
    $resultats= $bdd->query("SELECT * FROM releves ORDER BY ID_releves DESC LIMIT 1"); 
    // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
    $resultats->setFetchMode(PDO::FETCH_OBJ);  
   
   
   $i = -1;//variable pour la boucle de récupération des données
   $val = array();//tableau qui contiendra toutes nos donnée de maniere simplifier
   
   foreach ($resultats as $row) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
       foreach ($row as $value) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
           
           $i= $i+1;//chaque valeur de $row est ajouter à une nouvelle case du tableau en incrementant $i pour chaque passage de la boucle
           $val[$i]=$value;          
       }  
   }

   $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y à %Hh%imin') FROM `releves` ORDER BY ID_releves DESC LIMIT 1");
   // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
   $resultats->setFetchMode(PDO::FETCH_OBJ); 

    $j=-1;
    $date_time =array();
    foreach ($resultats as $row_date) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
        foreach ($row_date as $value_date) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
           
           $j= $j+1;
           $date_time[$j] =$value_date ; 
        }
    }
    
   //********** Bloc permettant la convertion de la vitesse km/h en m/s **********
   $ventkm = $val[2];
   $ventconvert = $ventkm/3.6;
   $ventms = round($ventconvert, 3);
   
   //********** Bloc permettant l'affichage des données **********
    ?>
    <div class="col-lg-5">
        <u><b> <?php echo "Dernier relevé du : " ?></div>  </b></u> <div class="col-lg-6"> <?php echo "$date_time[0]"; ?> </div> <br><br>
        
    <div class="col-lg-5"> <u><b> <?php echo "Force du vent de l'éolienne : "?> </div> </b></u> <div class="col-lg-6"> <?php echo "$val[2] km/h soit $ventms m/s"; ?> </div> <br><br>
        
    <div class="col-lg-5"> <u><b> <?php echo "Puissance produite : "?> </div> </b></u> <div class="col-lg-6"> <?php echo "$val[3] Watts"; ?> </div> <br><br> 
        
    <div class="col-lg-5"> <u><b> <?php echo "Pourcentage de vitesse de l'éolienne : "?> </div> </b></u> <div class="col-lg-6"> <?php echo "$val[4]%";?> </div> <?php
}



//**********  Fonction recupére et affiche dans un tableau touts les relevé effectué par ordre du plus recent au plus ancien **********

function hist_releve(){
    
    require 'connexion.php';    
    // on va chercher la derniere entrée dans la table des relevés
    if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
        $inc_page = $_GET["tab_page"];
        //echo $inc_page;
    }else{
        $inc_page=0;
    }
    $pagination = $inc_page * 10;
    
    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y à %Hh%imin'),eoliennes.nom_eol, scenarios.nom_scenar, sequences.duree, releves.puissance, releves.consigne,  releves.force_vent as km, ROUND(releves.force_vent/3.6, 1) as ms
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios
                            JOIN sequences
                            ON scenarios.ID_scenarios = sequences.ID_scenarios

                            ORDER BY releves.date_time DESC LIMIT 10 OFFSET $pagination"); 
    // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
    $resultats->setFetchMode(PDO::FETCH_OBJ); 
   
    
    $i=-1;
    foreach ($resultats as $row) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
        ?> <tr> <?php
        foreach ($row as $value) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
            
            
            $i = $i+1;
            $test[$i] =$value ;
            ?><td><center> <?php echo $test[$i]; ?></td>
             <?php
        }
        ?> </center> </tr> <?php
    }
    
    
    
    
}


function count_entree(){
    
    require 'connexion.php';
        
    $resultats= $bdd->query("SELECT count(*)
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios
                            JOIN sequences
                            ON scenarios.ID_scenarios = sequences.ID_scenarios");
    $resultats->setFetchMode(PDO::FETCH_OBJ);
    

    foreach ($resultats as $row){
        foreach ($row as $value) {    
        
        return $val_entree= $value;
        }
    }  
   
}

function modulo_page_tab(){
    $nb_entree=0;
    
    $nb_entree = count_entree();
    $modulo = $nb_entree /10; ## en fonction du nombre de valeur souhaité par tableau. 
    #                         ## voir avec valeur XXX de fonction hist_releve() variable "$pagination = $inc_page * XXX ;" 
    #                         ## doit correspondre à la LIMIT de la requete

    if (is_int($modulo)){
        $int_pagination = variant_int($modulo);
        return $int_pagination;
    }else{
        $int_pagination = variant_int($modulo) +1;
        return $int_pagination;
    }
}

function releves_chart(){
     
    require 'connexion.php';

    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%Hh%imin%s'), releves.force_vent, releves.puissance
        FROM releves
        JOIN `tests` 
        ON releves.ID_releves = tests.ID_releves
        LIMIT 30");
    $resultatsGraph = $resultats ->fetchAll();// transforme l'objet du PDO en tableau
                     
    foreach ($resultatsGraph as $valGraph){//entre dans le 1er tableau
        echo "['".$valGraph[0]."', ".$valGraph[1].", ".$valGraph[2]."],";//Affichage des valeurs de la BDD   
    }
}

function releves_chart_ms(){
     
    require 'connexion.php';

    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%Hh%imin%s'), releves.force_vent/3.6 , releves.puissance
        FROM releves
        JOIN `tests` 
        ON releves.ID_releves = tests.ID_releves
        LIMIT 30");
    $resultatsGraph = $resultats ->fetchAll();// transforme l'objet du PDO en tableau
                     
    foreach ($resultatsGraph as $valGraph){//entre dans le 1er tableau
        echo "['".$valGraph[0]."', ".$valGraph[1].", ".$valGraph[2]."],";//Affichage des valeurs de la BDD   
    }
}

function date_dern_relev(){
    
   require 'connexion.php';
   $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y') FROM `releves` ORDER BY date_time DESC LIMIT 1");
   // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
   $resultats->setFetchMode(PDO::FETCH_OBJ); 

    $j=-1;
    $date_time =array();
    foreach ($resultats as $row_date) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
        foreach ($row_date as $value_date) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
           
           $j= $j+1;
           $date_time[$j] =$value_date ; 
        }
    }
    
    echo "$date_time[0]";
    
}