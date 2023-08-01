#### Présentation
Piechart est un programme en C qui génère un graphique de type Pie Chart.
Lancer le programme en mettant en argument les pourcentages séparés par une virgule, puis les noms (étiquettes).
*Exemple :* `piechart 65,20,5,5,5 USA,UK,Canada,Other,Australia nomdufichier`

#### Arguments
Il faut rentrer dans l'ordre : 
1. les pourcentages
2. le nom des sections
3. le titre (nom du fichier)
4. les arguments optionnels

##### Arguments optionnels
* 3d : affichage du diagramme en perspective (effet 3d)
* [r],[v],[b] : couleur du fond en RVB : [r],[v],[b] sont des nombres compris entre 0 et 255

N.B.: par défaut, c-à-d s'il n'y a aucun argument optionnel saisi, le fond est blanc et l'affichage en 2d.

*Exemple :* `piechart 36,10,10,44 France,Espagne,Allemagne,Italie nomdufichier 3d 150,190,210`
