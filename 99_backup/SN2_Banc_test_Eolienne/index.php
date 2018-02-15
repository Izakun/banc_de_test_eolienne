<?php
    include 'header.php';//ajoute l'entete, navbar etc
?>
    <!-- Carousel d'en-tete, permet d'afficher l'image de présentation -->
    <header id="myCarousel" class="carousel slide">
        <!-- Wrapper for slides -->
        <div class="carousel-inner">
            <div class="item active">
                <div class="fill" ><center><img src="images/caroussel.jpg"/></center></div>
                <div class="carousel-caption">
                    <h2>Banc de test Eolienne SN2 2017</h2><!-- titre de la page présente sur l'image d'accueil -->
                </div>
            </div>
        </div>
    </header>

    <!-- Page Content -->

        
        <!-- cadre presentation, de bienvenue et btn -->
        <div class="row">
            <div class="col-lg-1"></div>
            <div class="col-lg-11">
                <h2 class="page-header">
                    Bienvenue sur l'interface Web de supervision du banc de test eolienne
                </h2>
            </div>
           
            
            <div class="col-md-2"></div>
            
            <div class="col-md-4">
                
                <div class="panel panel-default"><!-- cadre pour présenter et btn de la page d'historique -->
                    <div class="panel-heading">
                        <h4><span class="glyphicon glyphicon-calendar"></span>Historique</h4>
                    </div>
                    <div class="panel-body">
                        <p align="justify"> Sur la page historique vous pourrez voir les derniers scénarios ayant été lancés sur le système de la soufflerie via l'application, ainsi que d'observer la production, en Watt, de l'éolienne.</p>
                        <a href="historique.php"  class="btn btn-primary"><span class="glyphicon glyphicon-chevron-right"></span> En voir plus</a>
                    </div>
                </div>
            </div>
            
            <div class="col-md-4">
                <div class="panel panel-default"><!-- cadre de présentation et btn de page vision instantanée -->
                    <div class="panel-heading">
                        <h4><span class="glyphicon glyphicon-eye-open"></span> Vision instantanée</h4>
                    </div>
                    <div class="panel-body">
                        <p align="justify"> Sur la page de vision instantanée vous pourrez voir la production éléctrique et la vitesse du vent produit par  l'éolienne choisie en direct, et ce, à l'aide d'un graphique dynamique. </p>
                        <a href="vision.php" class="btn btn-primary"><span class="glyphicon glyphicon-chevron-right"></span> En voir plus</a>
                    </div>
                </div>
            </div>
        </div>
        <!-- /.row -->

        <hr>
    
    <!-- /.container -->
<?php
    include 'footer.php';//permet d'ajouter le pied de page 
    