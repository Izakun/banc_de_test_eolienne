<?php 
	$PARAM_hote='localhost';		// Le chemin vers le serveur
	$PARAM_port='3305';			// numéro du port à utiliser
	$PARAM_nom_bd='banc_test_eolienne';	// le nom de la BDD
	$PARAM_user='UserWeb';			// nom d'utilisateur de la BDD	
	$PARAM_password='DevWeb';		// Password de l'utilisateur 
	
        try{					//Essaye de ce connecter à la base de données 
	$bdd = new PDO('mysql:host='.$PARAM_hote.';port='.$PARAM_port.';dbname='.$PARAM_nom_bd, $PARAM_user, $PARAM_password)
                or die("Impossible de se connecter : " . mysql_error());	//requete de connexion
        }
        catch (Exception $e){			//Si la connexion ne peut pas ce faire, alors entre dans cette boucle?>							
            <div class="col-md-2"></div>
            <div class="col-lg-12">
            <div class="alert alert-danger"><strong>
        
                <span class="glyphicon glyphicon-warning-sign"></span>

                    <?php die( "Erreur, impossible de ce connecter à la base de données.
                    <br/> 
                    Vérifiez vos paramètres de connexion ainsi que votre connexion réseau ou contactez un technicien.");
					//message d'erreur à afficher?>
                </strong> 
            </div>
            </div><?php  //Creer une section avec affichage de message d'erreur dans un cadre d'alerte rouge
        }
