<html>
<head>
	<script language="javascript" type="text/javascript">
		var URL = "http://localhost/sn2_banc_test_eolienne/test.php";
		function rafraichir() {
                    if (window.XMLHttpRequest) xhr = new XMLHttpRequest();
                    else if (window.ActiveXObject) xhr = new ActiveXObject('Microsoft.XMLHTTP');
                    else alert('JavaScript : votre navigateur ne supporte pas les objets XMLHttpRequest...');
                    xhr.open('GET',URL+"?anticache="+new Date().getTime(),true);
                    //xhr.open('GET',URL,true);
                    xhr.onreadystatechange = ajaxReponse;
                    xhr.send(null);
                                
		}
 
		function ajaxReponse() {
                    if (xhr.readyState === 4) {
                        document.getElementById("refresh_graph").innerHTML=xhr.responseText; 

                        var timer=setTimeout("rafraichir()",10000); 
                    }
		}
</script>
<?php
    include'header.php';

?>
</head>
<body onLoad="javascript:rafraichir();">
<div class="col-lg-12">
    <h1 class="page-header">
       <span class="glyphicon glyphicon-eye-open"></span> Vision instantanée <small> Observez l'évolution de la production de l'éolienne.</small>
    </h1>
        <ol class="breadcrumb">
        <li class="active">
            <a href="vision.php"><span class="glyphicon glyphicon-chevron-right"></span> Passez en kilomètres par heure</a>
        </li>
    </ol>
</div>



<div class="row">
        <div class="col-lg-1"></div>
            <h2 class="page-header">

            </h2>
        </div>


    <table>
         <tr>
		<td id="refresh_graph">    
                    

                       
		</td>
	</tr>
    </table>
</body>
</html>

<?php 
        include 'footer.php';