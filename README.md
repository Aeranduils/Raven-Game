# Raven-8IAR128
Projet Raven du cours 8IAR125 de l'UQAC

------------------------------------
Projet réalisé par
Romain Salha SALR11060106
Rémi Espié ESPR01020004
Louise Bourey BOUL01589901
Alexandre MIGNOT MIGA291220014
Julie NEIGE NEIJ03529905
Mobou Tachago Murielle MOBM18550004
Florian Fritz FRIF04109909

-----------------------------------
3 - A
-----------------------------------
Alexandre MIGNOT / Julie NEIGE

La classe RocketLauncher a été enrichie par de nouvelles règles, avec maintenant 25 règles. Pour cela, la classe Weapon_RocketLauncher a été modifiée. Nous avons ajouté des règles pour les variables floues qui sont : état munitions, distance de la cible et la désirabilité de l’arme.  Pour chacune de ces variables floues nous avons maintenant un ensemble de 5. 

Le fichier modifié est :
Weapon_RocketLauncher.pp
 
-----------------------------------
3 - B
-----------------------------------
Alexandre MIGNOT / Julie NEIGE

La visée des bot a été modifiée, afin d’introduire des notions de flous. Nous prenons maintenant en compte les variables suivantes dans la visée des bot : la distance de la cible, la vitesse de déplacement de la cible, le temps que la cible est visible. En combinant ces variables et en gardant en tête l'esprit d’un shooter, on peut déterminer la visée pour chacune des règles. Par exemple, quand notre cible est à courte distance, qu’elle est lente et qu’elle est toujours visible, alors on obtient une très bonne précision pour ce tir.

Les fichiers modifier sont :
Raven_WeaponSystem.cpp
Raven_WeaponSystem.h
-----------------------------------
3 - C
-----------------------------------
Louise Bourey : Mise en place de la récupération d’armes. Dans un premier temps, le joueur doit établir la position de la base (clic milieu souris + W). Une fois qu’un bot dans l’équipe meurt, il laisse son arme dans la liste d’armes de l’équipe. Cette dernière pourra être récupérée quand un bot de l’équipe passe sur la position de la base. La liste est ensuite vidée une fois que les armes sont prises.
Raven_Game.cpp :
- ajout de la sélection de la position de la base + son visuel (croix verte).
Weapon_System.cpp :
- ajout des fonctions LeaveWeapon (utilisant une liste pour stocker les armes de l’équipe) et CollectWeapon.
Raven_Bot.cpp : 
-appeler les deux fonctions précédentes quand le bot meurt ou quand sa position est égale à celle de la base.

Rémi Espié : Mise en place de la création d’équipe par un joueur humain et du ciblage d’un ennemi par cette équipe. Chaque bot de l’équipe -dont le bot joueur- réagira au mieux pour attaquer l’ennemi sélectionné tout en cherchant à se sauvegarder et à récupérer de l’équipement.
Un bot peut être sélectionné grâce à un double clic droit.
Une cible est sélectionnée (ou désélectionner si le joueur re clic sur la cible ou si il clic dans le vide) avec le clic milieu souris.
Un allié peut être ajouté ou supprimé avec le clic milieu souris + T. L’allié affronte la cible du joueur si il en a sélectionner une.
Raven_Game.cpp : 
ajout de la sélectionner d’allié et de cible, et de leur affichage sur l’interface, ainsi que d’une liste de bot allié.
Raven_Bot.cpp :
ajout d’un booléen “allié” aux bots, des différentes fonctions pour les ajouter ou les supprimer.
Modification de la réflexion des bots pour que le joueur humain ou qu’un bot allié puisse cibler un bot particulier.

-----------------------------------
3 - D
-----------------------------------
Romain Salha / Florian Fritz / Mobou Tachago Murielle

Creation de CData.cpp/h et CNeuralNet.cpp/h et LearningBot.cpp/h

Raven_Game.cpp:
-Modification dans la méthode Update(), si le bot est possédé par un joueur humain alors on lance l’apprentissage sur celui-ci.
-Création de TrainThread() qui lance l’apprentissage.
-Ajout d’un booléen en parametres de AddBots() pour indiquer s’il s’agit d’un bot apprenant. (AddBots(unsigned int NumBotsToAdd) ------> Raven_Game::AddBots(unsigned int NumBotsToAdd, bool isLearningBot))

LearningBot.cpp:  
            -Utilisation du réseau de neurones et du modèle appris sur le joueur humain pour la décision de tir dans la méthode Update().

CNeuralNet.cpp, CData.cpp :
-Modification du nombre d'itérations à 1000 dans les classes CNeuralNet(), CData()
-Créer la fonction CreateTrainingSetFromData() qui crée le training set des fonctions des données définies().
-Création d’une variable LayerID permettant d’identifier chacune des couches du neurone.
-Pas réussi à afficher les performances du bot.


-----------------------------------
3 - E
-----------------------------------
Alexandre MIGNOT / Julie NEIGE

Ajout du but, Goal_Do_a_360 le but est d'ajouter au bot la possibilité de faire un 360 sur lui-même. Malheureusement ce but n’est jamais choisi par le jeu, il n’est donc jamais exécuté.

Les fichiers modifier sont :
Goal_Do_a_360.cpp
Goal_Do_a_360.h
Raven_Goal_Types.cpp
Raven_Goal_Types.h
-----------------------------------
3 - F
-----------------------------------

/!\ PAS FAIT (╯°□°）╯︵ ┻━┻  PARDON  /!\
