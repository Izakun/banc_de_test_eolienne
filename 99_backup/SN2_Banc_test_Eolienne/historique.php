<?php
    include 'header.php';
    require_once 'fonctions.php';
    
        if( isset($_GET['scen']) && is_numeric($_GET['scen']) )
    $hist_scenario = $_GET['scen'];
    else
    $hist_scenario = 0;
    if( isset($_GET['page']) && is_numeric($_GET['page']) )
    $page = $_GET['page'];
    else
    $page = 1;
    

    
?> <!-- Fin en-tete, Containe-->


<div class="col-lg-12">
    <h1 class="page-header">
        <span class="glyphicon glyphicon-calendar"></span>Historique <small> des derniers relevés effectués</small>
    </h1>
</div>


<div class="row">
        <div class="col-lg-1"></div>
        <div class="col-lg-11">
        </div>
        <div class="col-md-1"></div>
        <div class="col-lg-10">

            
            
                    
        <?php if (empty($hist_scenario) || $hist_scenario<1){
        ?>
            <div class="panel panel-primary"> <!-- bloc d'affichage du dernier relevés effectué -->
            <div class="panel-heading">
                <h3 class="panel-title"><i class="glyphicon glyphicon-list"> </i> Dernier relevé effectué </h3>
            </div>
            

            <div class="panel-body">
                <?php
                
                dernier_releve();
                
                ?>
                
            </div>
        </div>
            
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
                                    hist_releve();
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
                            </tr>
                        </thead>
                        <tbody>                            
                                <?php
                                    hist_releve_scenario($hist_scenario);
                                ?>
                        </tbody>
                    </table>

            
      <?php }?>
                    
                            <?php
                     // ****** Le bloc suivant permet de connaitre la "page" du tableau d'historique et affiche en conscéquences les boutons de page suivante et précédente
                        if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
                            $tab_page = $_GET["tab_page"];
                            $val_inc_tab= 1 + $tab_page;
                            
                        }else{
                            $val_inc_tab= 1;
                        }
                    
                        if(isset($_GET['tab_page']) AND !empty($_GET['tab_page'])){
                            $tab_page = $_GET["tab_page"];
                            $val_dec_tab= $tab_page -1;
                        }else{
                            $val_dec_tab= -1;
                        }
                        
                        $pagination_max = modulo_page_tab($hist_scenario);
                        
                        echo '<center>';    
                        
                        if ($val_dec_tab >=0){
                        echo '<a href="historique.php?scen='.$hist_scenario.'&tab_page='.$val_dec_tab.'"  class="btn btn-primary"><span class="glyphicon glyphicon-chevron-left"></span> relevés plus recents</a>';
                        }
                        echo ' ';
                        if($val_inc_tab < $pagination_max){
                        echo '<a href="historique.php?scen='.$hist_scenario.'&tab_page='.$val_inc_tab.'" class="btn btn-primary">relevés plus anciens <span class="glyphicon glyphicon-chevron-right"></span></a>';
                        }
                
                        echo '</center>';?>
                </div>

                            <hr>
                            <h1><small> Selectionnez un historique de scénario précis</small></h1>
                         <?php
                            btnlistescenar();// Fonction qui permettra d'acher une bouton d'historique pour chaque scénario existant
                         
                         ?>
            </div>  
    </div>
            
</div>
    <!-- /.container -->
    
</body>
<?php
    include 'footer.php';// Ajoute le pied de page