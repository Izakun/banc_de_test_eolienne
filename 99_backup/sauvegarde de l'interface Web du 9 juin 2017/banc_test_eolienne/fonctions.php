<?php
//require_once 'historique_releves.php';



//<!-- #################################### Fonction recupére et affiche le dernier relevé effectué ####################################-->
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



//<!-- #################################### Fonction recupére et affiche dans un tableau touts les relevé effectué par ordre du plus recent au plus ancien ####################################-->

function hist_releve(){
    
    require 'connexion.php';    
    // on va chercher la derniere entrée dans la table des relevés
    if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
        $inc_page = $_GET["tab_page"];
        //echo $inc_page;
    }else{
        $inc_page=0;
    }
    $pagination = $inc_page * 20;
    
    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y à %Hh%imin%ss'),eoliennes.nom_eol, scenarios.nom_scenar, releves.puissance, releves.consigne,  releves.force_vent as km, ROUND(releves.force_vent/3.6, 1) as ms
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios


                            ORDER BY releves.date_time DESC LIMIT 20 OFFSET $pagination"); 
    // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
    $resultats->setFetchMode(PDO::FETCH_OBJ); 
   
    $i=-1;
    foreach ($resultats as $row) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
        ?> <tr> <?php
        foreach ($row as $value) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
             
            $i = $i+1;
            $champ[$i] =$value ;
            ?><td><center> <?php echo $champ[$i]; ?></td><!-- affiche les valeur de la base de données au centre de la case suivante -->
             <?php
        }
        ?> </center> </tr> <?php
    }
}




// #################################### Bloc permettant de récupérer le nom du scénario choisi pour afficher son historique ####################################-->

function nom_scen_use($id_scenario){// Récupère l'id du scénario souhaité via l'appel de la fonction pas le bouton
        require 'connexion.php';
    
    $resultats= $bdd->query("SELECT nom_scenar FROM scenarios WHERE ID_scenarios =$id_scenario");
    $resultats->setFetchMode(PDO::FETCH_OBJ);
    $nom_scenar;
    foreach ($resultats as $row) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
        foreach ($row as $value){
        $nom_scenar=$value;//le nom du scenario est récupéré dans la variable $nom_scenar
        }
    }
    echo $nom_scenar;// Affiche alors le nom du scénario choisi
}




//<!-- ####################################  ####################################-->

function hist_releve_scenario($id_scenario){
    
    require 'connexion.php';    
    // on va chercher la derniere entrée dans la table des relevés
    if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
        $inc_page = $_GET["tab_page"];
        //echo $inc_page;
    }else{
        $inc_page=0;
    }
    $pagination = $inc_page * 20;
    
    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y à %Hh%imin%ss'),eoliennes.nom_eol, releves.puissance, releves.consigne,  releves.force_vent as km, ROUND(releves.force_vent/3.6, 1) as ms, tests.reference
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios
                            
                            WHERE tests.ID_scenarios = $id_scenario

                            ORDER BY releves.date_time DESC LIMIT 20 OFFSET $pagination"); 
    // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
    $resultats->setFetchMode(PDO::FETCH_OBJ); 
   
    $i=-1;
    foreach ($resultats as $row) {//la variable résultat est un tableau de tableau. Il faut donc faire une premiere boucle foreach pour effectuer une action sur chaque sous-tableau
        ?> <tr> <?php
        foreach ($row as $value) {//$row est donc un tableau associatif. Il faut un nouveau foreach pour recuperer les valeurs de ce tableau.
             
            $i = $i+1;
            $champ[$i] =$value ;
            ?><td><center> <?php echo $champ[$i]; ?></td>
             <?php
        }
        ?> </center> </tr> <?php
    }
}




//<!-- #################################### Bloc permettant de connaitre le nombre d'entree total dans la base de données ou pour un scénario donné par paramètre ####################################-->
function count_entree($id_scenario){
    
    require 'connexion.php';
    
    $resultats;
    switch ($id_scenario){
        case 0://Si il n'y a pas de scénario choisi, récupère le nombre d'entrées total dans la table de relevés
                $resultats= $bdd->query("SELECT count(*)
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios
");
                break;
        default://Si un scénario est choisi, récupère le nombre d'entrées des relevés d'un scénario précis.(par date du plus récent au plus ancien)
            $resultats= $bdd->query("SELECT count(*)
                            FROM releves
                            JOIN `tests` 
                            ON releves.ID_releves = tests.ID_releves
                            JOIN `eoliennes`
                            ON tests.ID_eolienne = eoliennes.ID_eolienne
                            JOIN scenarios
                            ON tests.ID_scenarios = scenarios.ID_scenarios

                            
                            WHERE tests.ID_scenarios =$id_scenario

                            ORDER BY releves.date_time");  
    }

    $resultats->setFetchMode(PDO::FETCH_OBJ);
    

    foreach ($resultats as $row){
        foreach ($row as $value) {    
        
        return $val_entree= $value;//recupère le nombre souhaité et le retourne à la fonction "modulo_page_tab()"
        }
    }  
   
}






//<!-- ####################################Permet de calculer le nombre de pages nécessaire au tableau####################################-->
function modulo_page_tab($id_scenario){
    $nb_entree=0;

    $nb_entree = count_entree($id_scenario);
    
    $modulo = $nb_entree /20; ## en fonction du nombre de valeur souhaité par tableau. 
    #                         ## voir avec valeur XXX de fonction hist_releve() variable "$pagination = $inc_page * XXX ;" 
    #                         ## doit correspondre à la LIMIT de la requete

	if (is_numeric($modulo))
    	{
	        if ((int) $modulo == $modulo) //Si la valeur du modulo est un int, alors:
        	{ 	
			$int_pagination = (int)$modulo;// La variable $int_pagination prend la valeur de $modulo (transformé de tableau en entier)
			return $int_pagination;//renvois la valeur de la variable $int_pagination
		}
        	else //Sinon, si le modulo n'est pas un entier, mais un float:
        	{	 
			$int_pagination = (int)$modulo +1;//La valeur de $int_pagination est égale à la partie entière du modulo +1		
        		return $int_pagination;//renvois la valeur de la variable $int_pagination
		}
    	}

}




//<!-- #################################### Bloc permettant de récupérer les valeurs du mode instantané pour le graphique en Km/h ####################################-->

function releves_chart(){
     
    require 'connexion.php';

    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%Hh%imin%s') as date, releves.force_vent, releves.puissance FROM releves JOIN `tests` ON releves.ID_releves = tests.ID_releves WHERE tests.ID_scenarios = 0 order by tests.ID_releves DESC limit 100 
        ");
    $resultatsGraph = $resultats ->fetchAll();// transforme l'objet du PDO en tableau
                     
    foreach ( array_reverse($resultatsGraph) as $valGraph){//entre dans le 1er tableau
        echo "['".$valGraph[0]."', ".$valGraph[1].", ".$valGraph[2]."],";//Affichage des valeurs de la BDD   
    }
}





//<!-- #################################### Bloc permettant de récupérer les valeurs du mode instantané pour le graphique en m/s ####################################-->
function releves_chart_ms(){
     
    require 'connexion.php';

    $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%Hh%imin%s') as date, releves.force_vent/3.6, releves.puissance FROM releves JOIN `tests` ON releves.ID_releves = tests.ID_releves WHERE tests.ID_scenarios = 0 order by tests.ID_releves DESC limit 100");
    $resultatsGraph = $resultats ->fetchAll();// transforme l'objet du PDO en tableau
                     
    foreach (array_reverse($resultatsGraph) as $valGraph){//entre dans le 1er tableau
        echo "['".$valGraph[0]."', ".$valGraph[1].", ".$valGraph[2]."],";//Affichage des valeurs de la BDD   
    }
}




//<!-- ####################################  ####################################-->
function date_dern_relev(){
    
   require 'connexion.php';
   $resultats= $bdd->query("SELECT DATE_FORMAT(date_time, '%d/%m/%Y à %Hh%imin%ss') FROM `releves` ORDER BY date_time DESC LIMIT 1");
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





//<!-- #################################### Bloc permettant l'affichage des boutons de selection de scénario si ces derniers ont des relevés associés ####################################-->

function btnlistescenar(){
    require 'connexion.php';
    $resultats= $bdd->query("SELECT ID_scenarios,nom_scenar FROM `scenarios`");
   // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
   $resultatslistscenar = $resultats ->fetchAll();
   
   echo '<a href="historique.php"  class="btn btn-perso-prim-clair"> historique global <span class="glyphicon glyphicon-chevron-right"></span></a> ';//Affiche le bouton de retour à l'historique global
   
   foreach ($resultatslistscenar as $row){
       if ($row['ID_scenarios'] != 0){// Permet de ne pas rentrer dans la boucle si l'ID du scénario est 0, qui est l'ID du mode instantanné
           
            $nom_scenario = $row['nom_scenar'];//recupère le nom du scénario
            $id_scenario = $row['ID_scenarios'];//recupère l'ID du scénario
            $count=check_nb_entrer_scenario($id_scenario);//count le nombre d'entrées du scénario
            if($count['0']>0){//Si le scénario souhaité possède au moins une entrée, alors affiche le bouton pour afficher son historique
            echo '<a href="historique.php?scen='.$id_scenario.'"  class="btn btn-perso-prim-clair"> '.$nom_scenario.' <span class="glyphicon glyphicon-chevron-right"></span></a> ';//Creer le bouton avec pour lien la page d'historique avec en "GET" la valeur du scénario souhaité
            }
            
        }

       }

}



//<!-- ####################################  ####################################-->

function check_nb_entrer_scenario($id_scenario){
    require 'connexion.php';
    
    $resultats= $bdd->query("SELECT count(*)
                            FROM tests
                            JOIN scenarios on scenarios.ID_scenarios = tests.ID_scenarios
                            where tests.ID_scenarios = $id_scenario");
   // on dit qu'on veut que le resultat soit recuperable sous forme d'objet
   $resultatsnbentrer = $resultats ->fetchAll();
   $count = $resultatsnbentrer['0'];
   return $count;
}
