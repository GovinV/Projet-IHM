import QtQuick 2.9
import QtQuick.Controls 2.3

TutoForm {

    id: tutoForm
    width: 1280
    height: 800

    Rectangle {
        id: tuto
        width: (parent.width / 2048) * 1200
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: 0
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"


        ScrollView {
            id: scrollView
            width : parent.width-(parent.parent.width / 2048) * 48
            height: parent.height
            anchors.left: parent.left
            anchors.leftMargin: (parent.parent.width / 2048) * 24
            contentHeight: reglesContent.height+reglesContent.y+100
            clip: true

            Text {
                id: labelJeu
                width: parent.width
                height: 22
                color: "#e98515"
                text: qsTr("Le Jeu")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 20
                anchors.top: parent.top
                anchors.topMargin: 35
                horizontalAlignment: Text.AlignHCenter
            }
            Text {
                id: jeuContent
                width:parent.width*0.8
                anchors.top: parent.top
                anchors.topMargin: 70
                anchors.left: parent.left
                color: "#ffffff"
                text: qsTr("Le UNO est un célèbre jeu de cartes américain dont le vainqueur"+
                           " est la personne à s’être débarrassé de toutes ses cartes en pre"+
                           "mier. Dans cette application il est possible de faire des parties"+
                           " de 2 à 4 participants.")
                anchors.leftMargin: 75
                wrapMode: TextEdit.WordWrap
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
            }

            Text {
                id: labelCartes
                x: 0
                width: parent.width
                height: 22
                color: "#e98515"
                text: qsTr("Les cartes")
                anchors.top: parent.top
                horizontalAlignment: Text.AlignHCenter
                anchors.topMargin: 130
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 20
            }

            Text {
                id: cartesContent
                width:parent.width*0.8
                anchors.top: parent.top
                anchors.topMargin: 165
                anchors.left: parent.left
                color: "#ffffff"
                text: qsTr("108 cartes de base réparties de la manière suivante :\n"+
                            "\t• 19 cartes bleues numérotées de 0 à9 (le 0 en un seul exemplaire)\n"+
                            "\t• 19 cartes vertes numérotées de 0 à 9 (le 0 en un seul exemplaire\n"+
                            "\t• 19 cartes rouges numérotées de 0 à 9 (le 0 en un seul exemplaire)\n"+
                            "\t• 19 cartes jaunes numérotées de 0 à 9 (le 0 en un seul exemplaire)\n"+
                            "\t• 8 cartes «+2» (2 de chaque couleur)\n"+
                            "\t• 8 cartes «inversion» (2 de chaque couleur)\n"+
                            "\t• 8 cartes «passe ton tour» (2 de chaque couleur)\n"+
                            "\t• 4 cartes «changement de couleur»\n"+
                            "\t• 4 cartes «+4» ")
                anchors.leftMargin: 75
                wrapMode: TextEdit.WordWrap
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
            }

            Text {
                id: labelRegles
                x: 0
                width: parent.width
                height: 22
                color: "#e98515"
                text: qsTr("Les Règles")
                anchors.top: parent.top
                horizontalAlignment: Text.AlignHCenter
                anchors.topMargin: 335
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 20
            }
            Text {
                id: reglesContent
                width:parent.width*0.8
                anchors.top: parent.top
                anchors.topMargin: 370
                anchors.left: parent.left
                color: "#ffffff"
                text: qsTr("Tout d’abord, chaque joueur se voit attribuer 7 cartes. "+
                           "Le reste des cartes fait office de pioche. Pour commencer"+
                           ", une carte présente dans la pioche et tirée au hasard et "+
                           "fait office de point de départ ensuite un joueur est sélectionné"+
                           " aléatoirement pour commencer la partie. Il doit recouvrir la "+
                           "carte de la pioche par une carte d’une même couleur, du même "+
                           "chiffre ou du même symbole. Si le joueur ne peut pas jouer, il "+
                           "a la possibilité de poser une carte « changement de couleur » ou "+
                           "« +4 ». Dans le cas où le joueur ne possède aucune de ces cartes, "+
                           "il doit en piocher une. Si cette carte peut être jouée, il peut directement"+
                           " la poser, sinon il devra la conserver dans son jeu."+
                           "\nLorsque qu’un joueur n’a plus qu’une carte en sa possession,"+
                           " il doit appuyer sur le bouton « Uno » pour avertir tous les autres"+
                           " joueurs. S’il oublie de le faire et qu’un joueur s’en aperçoit, il "+
                           "devra piocher 2 cartes en pénalité."+
                           "\nLe premier des joueurs à s’être débarrassé de toutes ses cartes gagne "+
                           "et la partie contenue jusqu’à ce qu’il ne reste plus que 1 joueur.")
                anchors.leftMargin: 75
                wrapMode: TextEdit.WordWrap
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
            }

        }
        Rectangle
        {
            anchors.fill: parent
            color: Qt.rgba(0,0,0,0)
            border.color: "#ffffff"
            radius: 20
            border.width: (tutoForm.width / 2048) * 24
        }

    }
}

