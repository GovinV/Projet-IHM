import QtQuick 2.4

import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3

import Player 1.0

RoomMenuForm {
    id: roomMenu
    width: 1280
    height: 800

    property bool host: true
    property string name: "test Server"
    property string roomId: "123456789"
    property int player: 1
    property int playerMax: 4

    Connections{
        target: network

        onTmpReady: {
            print("ca a changé !")
        }
        onChangeMyRoomName:{
            name=new_name;
            roomName=new_name;
        }
    }

    Rectangle {
        id: gameMode
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        transformOrigin: Item.Center
        color: "#272727"
        radius: 20

        visible: parent.host

        ScrollView{
            width: parent.width - (parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * 48-50
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * 24
            anchors.left: parent.left
            anchors.leftMargin: (parent.parent.width / 2048) * 24

            clip: true

            contentHeight: 370

            Text {
                id: salonName
                width: parent.width
                height: 40
                text: qsTr("Nom du Salon")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }
            Rectangle
            {
                y: 40
                width: parent.width-30
                height: 60
                anchors.left: parent.left
                anchors.leftMargin: 15
                color: "#dddddd"
                TextInput {
                    id: nameInput
                    anchors.fill: parent
                    horizontalAlignment: Text.AlignHCenter
                    wrapMode: TextEdit.WordWrap
                    color: "#000000"
                    text: qsTr("Nouveau salon de jeu")
                    font.bold: true
                    font.family: "Tahoma"
                    font.pixelSize: 13
                    //validator: RegExpValidator { regExp: /[0-9a-zA-Z]{1,30}/ }
                }
            }

            Text {
                id: nbJoueurtext
                y: 100
                width: parent.width
                height: 40
                text: qsTr("Nombre de joeurs (2-4)")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }

            SpinBox {
                id: nbJoueur
                y: 140
                width: 120
                height: 30
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
                font.pointSize: 13
                font.family: "Tahoma"
                to: 4
                from: 2
                value: 4

            }

            Text {
                id: textType
                y: 170
                width: parent.width
                height: 40
                text: qsTr("Type de partie")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }

            RadioButton {
                id: radioType1
                x: 0
                y: 210
                Text {
                    id: type1
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: 50
                    text: qsTr("Partie simple")
                    font.bold: true
                    font.family: "Tahoma"
                    font.pixelSize: 13
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color: "#ffffff"
                }
                anchors.left: parent.left
                anchors.leftMargin: 10
                checked: true
            }
            RadioButton {
                id: radioType2
                x: 0
                y: 250
                Text {
                    id: type2
                    height: parent.height
                    anchors.left: parent.left
                    anchors.leftMargin: 50
                    text: qsTr("500 points")
                    font.bold: true
                    font.family: "Tahoma"
                    font.pixelSize: 13
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                    color: "#ffffff"
                }
                anchors.left: parent.left
                anchors.leftMargin: 10
            }

            Text {
                id: textIA
                y: 290
                width: parent.width
                height: 40
                text: qsTr("Activer les IA")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 13
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                color: "#ffffff"
            }

            CheckBox {
                id: checkBox
                y: 330
                anchors.horizontalCenterOffset: 0
                anchors.horizontalCenter: parent.horizontalCenter
            }

        }

        Button {
            id: save
            Text {
                id: saveText
                text: qsTr("Sauvegarder")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 15
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
            }

            onClicked:
            {
                print(nameInput.text);
                if(nameInput.text!=name)
                {
                    name=nameInput.text
                    roomName.text=nameInput.text;
                    network.changeRoomName(nameInput.text);
                }
                if(nbJoueur.value!=playerMax)
                {
                    playerMax=nbJoueur.value;
                    network.changeMaxPlayer(nbJoueur.value);
                }
            }

            width: parent.width
            height: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: (parent.parent.width / 2048) * 24
            background: Rectangle{
                color: save.hovered?"#e98515":"#484848"
            }
        }

        Rectangle {
            id: rectangle
            anchors.fill: parent
            radius: 20
            color: "#00000000"
            border.color: "#ffffff"
            border.width: (parent.parent.width / 2048) * 24

        }


    }


    Rectangle {
        id: playerListrect
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: parent.host?((parent.width / 2048) * (220)):0
        transformOrigin: Item.Center
        radius: 20

        ListView {
            id: playerListView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * (24+80)-50
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * (24+80)



            clip:true

            model: PlayerModel{
                list: playerList
            }

            delegate: Rectangle {
                height: 60
                Player{
                    width: playerListrect.width-(playerListrect.parent.width / 2048) * 48;
                    playerId: model.id
                    name: model.name
                    ready: model.ready
                }
            }
        }
        Button {
            id: button

            property bool isReady:false

            Text {
                id: textProfil
                text: host?qsTr("Demarer"):qsTr("Prêt")
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
            }

            onClicked: {
                network.setReady(!isReady);
                isReady=!isReady;
            }

            width: parent.width- (parent.parent.width / 2048) * 48
            height: 50
            anchors.bottom: parent.bottom
            anchors.bottomMargin: (parent.parent.width / 2048) * 24
            anchors.left: parent.left
            anchors.leftMargin: (parent.parent.width / 2048) * 24
            background: Rectangle{
                color: {
                    if(host)
                    {/*
                        if()
                            button.hovered?"#e98515":"#484848";
                        else*/
                        "#484848";
                    }
                    else
                        button.hovered?"#e98515":"#484848";
                }
            }
        }

        Rectangle {
            anchors.fill: parent;
            color: "#00000000"
            radius: 20
            border.width: (parent.parent.width / 2048) * 24
            border.color: "#ffffff"
        }
        Rectangle {
            id: namerect
            width: parent.width
            height: (parent.parent.width / 2048) * 80
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * (24)
            Text {
                id: roomName
                text: name
                font.bold: true
                font.family: "Tahoma"
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
                color: "#ffffff"
            }
            color: "#00000000"
        }

        Rectangle {
            id: rectangle1
            width: parent.width
            height: 1
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * (24+80)
            color: "#ffffff"
        }
    }

}




