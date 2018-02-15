<?php 
	$PARAM_hote='localhost';		// Le chemin vers le serveur
	$PARAM_port='3305';			// numéro du port à utiliser DOIT ETRE LE MEME QUE LE PORT "MySQL" de Wamp ! Necessitera certainement modification lors de l'upload
	$PARAM_nom_bd='banc_test_eolienne';	// le nom de la BDD
	$PARAM_user='UserWeb';			// nom d'utilisateur de la BDD	
	$PARAM_password='DevWeb';		// Password de l'utilisateur 
	
        try{
	$bdd = new PDO('mysql:host='.$PARAM_hote.';port='.$PARAM_port.';dbname='.$PARAM_nom_bd, $PARAM_user, $PARAM_password)
                or die("Impossible de se connecter : " . mysql_error());
        }
        catch (Exception $e){?>

            <div class="alert alert-danger"><strong>
        
                <span class="glyphicon glyphicon-warning-sign"></span>
                    <?php die( "Erreur, impossible de ce connecter à la base de données.
                    <br/> 
                    Vérifiez vos paramètres de connexion ainsi que votre connexion réseau ou contactez un technicien.");?>
                </strong> 
            </div><?php 
                    
        }