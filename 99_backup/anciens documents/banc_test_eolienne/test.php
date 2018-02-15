
<?php
include 'header.php';
    include 'fonctions.php';
?>
<!-- SCRIPT DE REALISATION GRAPHIQUE  -->
        <center>
            <?php 
                $nb_min = 1;
                $nb_max = 100;
                $nombre = mt_rand($nb_min,$nb_max);

                echo $nombre;
            ?>

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
                          chartArea:{left:100,top:100, width:625, height:170}
                        };
                        var chart = new google.visualization.LineChart(document.getElementById('chart_id'));
                        chart.draw(data, options);
                      }
                </script>

                <div id="chart_id" style="width: 800px; height: 300px;"></div>
                
                
            <?php 
                $nb_min = 1;
                $nb_max = 100;
                $nombre = mt_rand($nb_min,$nb_max);
                echo $nombre;
            ?>
        </center>