# Projet il-fait-combien.fr #


## À propos

Le principe de ce projet est de récupérer la température d'une pièce, par exemple grâce à une sonde, et de la présenter sur une page web.

Le fonctionnement résumé de la solution proposée est le suivant :  
La sonde, après mesure d'une température fait une requête Post au webservice en envoyant le nom de la sonde et la température. Le webservice stocke dans la base de données mongoDB la mesure et push la mesure de température au client connecté via socket.io

Le projet comporte : 
* un projet nodeJs comportant qui contient un webservice qui renvoit une page web côté client
* le code source utilisé par la sonde

Ce projet est pour moi une manière ludique de m'initier aux technologies utilisées. Il m'a demandé une dizaine d'heures de travail et est largement perfectible. Je suis bien entendu ouvert à toute sugestion afin d'améliorer le code source.

Une version de production de mon travail est disponible à l'adresse suivante [il-fait-combien.fr](htpp://www.il-fait-combien.fr)

## La sonde

Pour la sonde, j'ai utilisé le hardware suivant : 
* un arduino Uno
* un shield ethernet
* une sonde de température TMP36
* des fils!

## Application node js

Dans ce projet, j'utilise les frameworks suivants :
* [express.js](http://expressjs.com/)
* [hogan.js](http://twitter.github.io/hogan.js/)
* [mongoDB](http://www.mongodb.org/)
* [socket.io](http://socket.io/)
* [bower](http://bower.io/)

