<?php
    include 'header.php';
    require_once 'fonctions.php';
    
        if( isset($_GET['scen']) && is_numeric($_GET['scen']) )// verifie si une variable est présente en GET (passage par URL) pour le 								choix d'un scenario voulus
    $hist_scenario = $_GET['scen'];	 //si OUI, la varible $hist_scenario prend cette valeur
    else
    $hist_scenario = 0;			// sinon la varible $hist_scenario est a zero
    if( isset($_GET['page']) && is_numeric($_GET['page']) )// verifie si une variable est présente en GET (passage par URL) pour le 								choix de la page du tableau d'historique
    $page = $_GET['page']; 		//Si OUI, la variable $page prend cette valeur
    else
    $page = 1;				// Sinon la variable $page est a zero
    

    
?> <!-- Fin en-tete, Containe-->


<div class="col-lg-12">
    <h1 class="page-header">
        <span class="glyphicon glyphicon-calendar"></span>Historique <small> des derniers relevés effectués</small> <!-- affiche un titre de page -->
    </h1>
</div>


<div class="row">
        <div class="col-lg-1"></div>
        <div class="col-lg-11">
        </div>
        <div class="col-md-1"></div>
        <div class="col-lg-10">

            
            
                    
        <?php if (empty($hist_scenario) || $hist_scenario<1){ //Si on ne récupère pas de valeur de scenario du GET ou s'il est < 1
        ?>

<!-- #################################### bloc d'affichage du dernier relevés effectué ####################################-->
            <div class="panel panel-primary"> 
            <div class="panel-heading">
                <h3 class="panel-title"><i class="glyphicon glyphicon-list"> </i> Dernier relevé effectué </h3>
            </div>
            

            <div class="panel-body">
                <?php
                
                dernier_releve(); //Appel la fonction dernier_releve() de la page "fonctions.php"
                
                ?>
                
            </div>
        </div>
            
<!-- ####################################  ####################################-->

            <hr>
                <div class="panel-body">

                <div class="table-responsive"><!-- création du tableau d'historique des relevés -->
                    <table class="table table-bordered table-hover table-striped">
                        <thead>
                            <tr>
                                <th><center>Date heure</center></th>
                                <th><center>éolienne utilisée</center></th> 
                                <th><center>scénario utilisé</center></th> 
                                <th><center>puissance (W)</center></th>
                                <th><center>consigne (%)</center></th>
                                <th><center>force du vent (km/h)</center></th>
                                <th><center>force du vent (m/s)</center></th>
                            </tr>
                        </thead>
                        <tbody>                            
                                <?php
                                    hist_releve(); //Appel la fonction hist_releve() de la page "fonctions.php"
                                ?>
                        </tbody>
                    </table>
                    
                    <?php
            }
            else{
                        ?>
       
                    <h1><small> <?php echo "Scénario : ";
                    nom_scen_use($hist_scenario) ?> </small></h1>
            <hr>
                <div class="panel-body">

                <div class="table-responsive"><!-- création du tableau d'historique des relevés -->
                    <table class="table table-bordered table-hover table-striped">
                        <thead>
                            <tr>
                                <th><center>Date heure</center></th>
                                <th><center>éolienne utilisée</center></th> 
                                <th><center>puissance (W)</center></th>
                                <th><center>consigne (%)</center></th>
                                <th><center>force du vent (km/h)</center></th>
                                <th><center>force du vent (m/s)</center></th>
                                <th><center> Référence </center></th>
                            </tr>
                        </thead>
                        <tbody>                            
                                <?php
                                    hist_releve_scenario($hist_scenario);// Appel la fonction pour récupérer l'historique des relevé en 									 fonction du scénario voulu
                                ?>
                        </tbody>
                    </table>

            
      <?php }?>
<!-- ####################################  ####################################--> 
                            

<!-- #################################### bloc de gestion de page du tableau d'historique ####################################-->

<?php
                        if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
                            $tab_page = $_GET["tab_page"];
                            $val_inc_tab= 1 + $tab_page;//Si une valeur de pag est présente, on lui ajoute 1 pour aller a 								la page suivante
                            
                        }else{
                            $val_inc_tab= 1;	// Si il n'y a pas de valeur, le bouton est en valeur "1"
                        }
                    
                        if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
                            $tab_page = $_GET["tab_page"];
                            $val_dec_tab= $tab_page -1;	//Si une valeur de pag est présente, on lui retire 1 pour revenir a 								la page précédente
                        }else{
                            $val_dec_tab= -1;	// Si il n'y a pas de valeur, le bouton est en valeur "-1" qui lui permet de ne pas 							l'afficher
                        }

                        $pagination_max = modulo_page_tab($hist_scenario); // Appel la fonction permettant de calculer le nombre de page maximum necessaire au tableau pour l'affichage des boutons.

                       	//echo $pagination_max;
                        echo '<center>';    
                        
                        if ($val_dec_tab >=0){//Si la valeur est égale ou inférieur a zero, le bouton de page précédente ne s'afficher pas
                        echo '<a href="historique.php?scen='.$hist_scenario.'&tab_page='.$val_dec_tab.'"  class="btn btn-primary"><span class="glyphicon glyphicon-chevron-left"></span> relevés plus recents</a>';
                        }
                        echo ' ';
                        if($val_inc_tab < $pagination_max){//tant que la valeur $val_inc_tab est inférieur au nombre de page necessaire, 								     affiche le bouton de page suivante
                        echo '<a href="historique.php?scen='.$hist_scenario.'&tab_page='.$val_inc_tab.'" class="btn btn-primary">relevés plus anciens <span class="glyphicon glyphicon-chevron-right"></span></a>';
                        }
                
                        echo '</center>';?>
                </div>

<!-- ####################################  ####################################-->


<!-- #################################### bloc permettant l'affichage des  ####################################-->
                            <hr>
                            <h1><small> Selectionnez un historique de scénario précis</small></h1>
                         <?php
                            btnlistescenar();// Fonction qui permettra d'afficher un bouton d'historique pour chaque scénario existant dans 							la base de données
                         
                         ?>

<!-- ####################################  ####################################-->
            </div>  
    </div>
            
</div>
    <!-- /.container -->
    
</body>
<?php
    include 'footer.php';// Ajoute le pied de page
