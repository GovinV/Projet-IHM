import QtQuick 2.4
import QtQuick.Controls 2.3
import Server 1.0


ServerMenuForm {
    id: serverMenu
    width: 1280
    height: 800

    Connections{
        target: network
        onServerRoomNull:
        {
            noRoom.visible=none;
        }

        onServerlistChanged:
        {
            print("onServerlistChanged");
        }
    }

    Rectangle {
        id: gameMode
        x: 538
        y: 502
        //width: 204
        //height: 313
        width: (parent.width / 2048) * 327
        height: (parent.width / 2048) * 502
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (-440))
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        transformOrigin: Item.Center
        color: "#272727"
        radius: 20

        Button {
            id: soloButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onClicked: {
                playClick.play();                
                swipeVertical.setCurrentIndex(0);
                gameform.startGame();
            }

            Rectangle{
               id: soloBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: soloText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Solo") + rootItem.emptyString
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                 playSnap.play();
                if(this.hovered)
                {
                    soloBackground.opacity = 1;
                    //soloText.color="#e98515";
                }
                else
                {
                    soloBackground.opacity = 0;
                    //soloText.color="white";
                }
             }
        }

        Button {
            id: serverButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24+(parent.height-((parent.parent.width / 2048) * 24*2))/3
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onClicked: {
                playClick.play();
                network.createRoom("Test");
                swipeHorizontalServeur.setCurrentIndex(2);
                room.host=true;
            }

            Rectangle{
               id: serverBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: serverText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Créer Salon") + rootItem.emptyString
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                 playSnap.play();
                if(this.hovered)
                {
                    serverBackground.opacity = 1;
                    //tutoText.color="#e98515";
                }
                else
                {
                    serverBackground.opacity = 0;
                    //tutoText.color="white";
                }
             }
        }

        Button {
            id: tutoButton
            x: (parent.parent.width / 2048) * 24
            y: (parent.parent.width / 2048) * 24 + (parent.height-((parent.parent.width / 2048) * 24*2))/3*2
            width: parent.width-((parent.parent.width / 2048) * 24*2)
            height: (parent.height-((parent.parent.width / 2048) * 24*2))/3
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onClicked: {
                playClick.play();
                swipeHorizontalServeur.setCurrentIndex(0);
            }

            Rectangle{
               id: tutoBackground
               anchors.fill: parent
               color: "#e98515"
               opacity : 0
            }

             Text {
                 id: tutoText
                 color: "white"
                 anchors.fill: parent
                 text: qsTr("Tuto") + rootItem.emptyString
                 verticalAlignment: Text.AlignVCenter
                 horizontalAlignment: Text.AlignHCenter
                 font.bold: true
                 font.family: "Tahoma"
                 font.pixelSize: 20
             }

             onHoveredChanged: function(){
                 playSnap.play();
                if(this.hovered)
                {
                    tutoBackground.opacity = 1;
                    //tutoText.color="#e98515";
                }
                else
                {
                    tutoBackground.opacity = 0;
                    //tutoText.color="white";
                }
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
        id: serverList
        x: 532
        y: 511
        width: (parent.width / 2048) * 327*2.35
        height: (parent.width / 2048) * 502
        color: "#272727"
        radius: 20
        anchors.verticalCenter: parent.verticalCenter
        anchors.verticalCenterOffset: 0
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: ((parent.width / 2048) * (220))
        transformOrigin: Item.Center
        border.width: (parent.width / 2048) * 24
        border.color: "#ffffff"


        Text {
            id: noRoom
            color: "white"
            anchors.fill: parent
            text: qsTr("Aucun salon de jeu trouvé") + rootItem.emptyString
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.bold: true
            font.family: "Tahoma"
            font.pixelSize: 20
            visible: false;
        }

        ListView {
            id: serverListView
            width: parent.width-(parent.parent.width / 2048) * 48
            height: parent.height-(parent.parent.width / 2048) * 48
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.top: parent.top
            anchors.topMargin: (parent.parent.width / 2048) * 24

            clip:true

            model: ServerModel{
                list: serversList
            }

            delegate: Rectangle {
                height: 60
                Server{
                    width: serverList.width-(serverList.parent.width / 2048) * 48
                    name: model.name
                    serverId: model.id
                    player: model.player
                    playerMax: model.max
                }
            }
        }
    }
}
