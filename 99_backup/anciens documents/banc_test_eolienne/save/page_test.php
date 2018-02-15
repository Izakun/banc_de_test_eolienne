<?php
    include 'header.php';
    include 'fonctions.php';
?> <!-- Fin en-tete, Containe-->


<div class="col-lg-12">
    <h1 class="page-header">
        Test <small> faut bien faire des diagrammes magueule</small>
    </h1>
    <ol class="breadcrumb">
        <li class="active">
            <i class="glyphicon glyphicon-calendar"></i> Historique

            <a href="historique.php"><span class="glyphicon glyphicon-chevron-left"></span> derniers relevés</a>
            <a href="https://developers.google.com/chart/interactive/docs/gallery/linechart"><span class="glyphicon glyphicon-chevron-right"></span> google chart</a>
        </li>
    </ol>
</div>



<div class="row">
        <div class="col-lg-1"></div>
            <h2 class="page-header">

            </h2>
        </div>

            <center>
                <?php $date_dernier_test = "20/12/2012";
                echo "<h2> Derniers tests effectués le : $date_dernier_test</h2> "?>

                <script type="text/javascript" src="https://www.google.com/jsapi"></script>
                <script type="text/javascript">
                      google.load("visualization", "1", {packages:["corechart"]});
                      google.setOnLoadCallback(drawChart);
                      function drawChart() {
                        var data = google.visualization.arrayToDataTable([
                        ['heure', 'force du vent (en km/h)', 'puissance produite (en Watts)'],
                        
                         [ "5h23min12s", 236, 62],  [ "2 Mar", 295,  74],  [ "3 Mar", 300, 45],
                         [ "4 Mar", 306, 24],  [ "5 Mar", 311, 16],  [ "6 Mar", 317, 12],  
                         [ "7 Mar", 322, 74],  [ "8 Mar", 328, 26],  [ "09Mar", 334, 10],  
                         ["10 Mar", 339, 44],  ["11 Mar", 345, 36],  ["12 Mar", 351, 35],  
                         ["13 Mar", 357, 11],  ["14 Mar", 363, 45],  ["15 Mar", 369, 75],  
                         ["16 Mar", 375, 22],  ["17 Mar", 381, 15],  ["18 Mar", 387, 74],  
                         ["19 Mar", 393, 33],  ["20 Mar", 399, 65],  ["21 Mar", 406, 95],  
                         ["22 Mar", 412, 44],  ["23 Mar", 418, 35],  ["24 Mar", 425, 82],  
                         ["25 Mar", 431, 55],  ["26 Mar", 438, 25],  ["27 Mar", 444, 12],  
                         ["28 Mar", 451, 66,],  ["29 Mar", 458, 54],  ["30 Mar", 464, 42], 
                         ["31 Mar", 471, 85,], 
                        ]);
                        var options = {
                          title: '',
                          hAxis: {showTextEvery: 5},
                          vAxes: {0: {viewWindowMode:'explicit',
                                      viewWindow:{
                                                  max:510,
                                                  min:82
                                                  },
                                      gridlines: {color: 'transparent'},
                                      format:"# m/s"},
                                  1: {gridlines: {color: 'transparent'},
                                      format:"# Watts"}
                                  },
                          series: {0: {targetAxisIndex:0},
                                   1:{targetAxisIndex:1}
                                  },
                          colors: ["blue", "orange"],
                          chartArea:{left:100,top:100, width:500, height:150},
                        };
                        var chart = new google.visualization.LineChart(document.getElementById('chart_id'));
                        chart.draw(data, options);
                      }
                </script>

                <div id="chart_id" style="width: 800px; height: 300px;"></div>
            </center>


<?php releves_chart()?>
        <hr>

    <!-- /.container -->
<?php
    include 'footer.php';