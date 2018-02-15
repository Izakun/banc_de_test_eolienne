<head>
    <meta http-equiv="refresh" content="15;url=vision.php" />
</head>
<?php
    include 'header.php';
    include 'fonctions.php';

        
 ?><!-- Fin en-tete, Containe-->
 
<div class="col-lg-12">
    <h1 class="page-header">
       <span class="glyphicon glyphicon-eye-open"></span> Vision instantanée <small> Observez l'évolution de la production de l'éolienne.</small>
    </h1>
    <ol class="breadcrumb">
        <li class="active">
            <a href="vision_ms.php"><span class="glyphicon glyphicon-chevron-right"></span> Passez en mètres par seconde</a>
        </li>
    </ol>
</div>



<div class="row">
        <div class="col-lg-1"></div>
            <h2 class="page-header">

            </h2>
        </div>

            <center>
                <?php
                echo "<h2> Derniers tests effectués le : "; date_dern_relev(); ?></h2> <br/>
                <?php echo"affiche au maximum les 30 dernieres entrées";?>

                
                <!-- SCRIPT DE REALISATION GRAPHIQUE  -->
                <script type="text/javascript" src="https://www.google.com/jsapi"></script>
                <script type="text/javascript">
                    google.load;
                      google.load("visualization", "1", {packages:["corechart"]});
                      google.setOnLoadCallback(drawChart);
                      function drawChart() {
                        var data = google.visualization.arrayToDataTable([
                        ['heure', 'Force du vent (en Km/h)', 'Puissance fournie (en Watts)'],

                          <?php
                            releves_chart() // fonction qui permet de recupérer et d'afficher les 30 dernieres entrées de la bases de données
                        
                            //PARAMETRE DU TABLEAU:
                            ?>
                        ]);
                        var options = {
                          title: '',
                          hAxis: {showTextEvery: 5},
                          vAxes: {0: {viewWindowMode:'explicit',

                                      gridlines: {color: 'transparent'},
                                      format:"# km/h"},
                                  1: {gridlines: {color: 'transparent'},
                                      format:"# Watts"}
                                  },
                          series: {0: {targetAxisIndex:0},
                                   1:{targetAxisIndex:1}
                                  },
                          colors: ["blue", "orange"],
                          chartArea:{left:100,top:100, width:625, height:170},
                        };
                        var chart = new google.visualization.LineChart(document.getElementById('chart_id'));
                        chart.draw(data, options);
                      }
                </script>

                <div id="chart_id" style="width: 800px; height: 300px;"></div>

            </center>
        <hr>
    <!-- /.container -->
<?php
    include 'footer.php';?>