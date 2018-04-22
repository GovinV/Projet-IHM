
import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

import game.backend 1.0
import game.handmodel 1.0


GameForm {
    id: gameForm
    visible: true
    width: 1280
    height: 800

    Image{
        id:background
        source:"qrc:/img/bg.jpg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    Rectangle{
        height: 25; width:20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: list0.top
        color: "black"
    }
    Rectangle{
        height: 25; width:20
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: list1.bottom
        color: "black"
    }

    // PLAYER 0
    ListView{
        id:list0
        //STYLE
        width:parent.width
        height:150
        anchors.horizontalCenter: parent.horizontalCenter
        highlightRangeMode: ListView.StrictlyEnforceRange
        preferredHighlightBegin: width / 2 - 20-150*0.65*0.2
        preferredHighlightEnd: width / 2 + 20-150*0.65*0.2
        //interactive:false
        anchors.bottom: parent.bottom
        orientation:ListView.Horizontal
        //spacing: -50
        //clip:true;

        //DATA
        model:HandModel{
            list:hand_j0
        }
        delegate:Component{
            Carte{listdata:list0}
        }

    }

    // PLAYER 1
    ListView{
        rotation: {originX:width/2;originY:height/2;angle:180}
        id:list1

        //STYLE
        width:parent.width
        height:150
        anchors.horizontalCenter: parent.horizontalCenter
        highlightRangeMode: ListView.StrictlyEnforceRange
        preferredHighlightBegin: width / 2 - 20-150*0.65*0.2
        preferredHighlightEnd: width / 2 + 20-150*0.65*0.2
        //interactive:false
        anchors.top: parent.top
        orientation:ListView.Horizontal
        //spacing: -50
        //clip:true;

        //DATA
        model:HandModel{
            list:hand_j1
        }
        delegate:Component{
            Carte{listdata:list1}
        }
    }

    // START GAME BUTTON

    Rectangle{
        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        height: 20
        width:100
        color: "white"
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Start Game"
            font.pixelSize: 20
        }
        Frame{
            anchors.fill:parent
        }
        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("click");
                game.start();
                //game.test();
            }
        }
    }

    // UNO !

    Rectangle{
        objectName: "unoBt"
        id:unoBt
        height:100
        width:100
        radius: 15
        color:"red"
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        Text{
            text:"UNO"
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        signal unoBtPressed()

        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("UNO");
                unoBt.unoBtPressed()
            }
        }
    }

    Rectangle{
        signal contreUnoBtPressed()
        objectName: "contreUnoBt"
        id:contreUnoBt
        height:100
        width:200
        radius: 15
        color:"orange"
        anchors.right: unoBt.left
        anchors.bottom: parent.bottom
        Text{
            text:"CONTRE !"
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }



        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("CONTRE !");
                contreUnoBt.contreUnoBtPressed()
            }
        }
    }

    // DRAW CARD

    Rectangle{
        signal qdrawCardBtPressed()
        objectName: "drawCardBt"
        id:drawCardBt
        height:150
        width:height*0.65
        radius: 15
        color:"transparent"
        anchors.verticalCenter: parent.verticalCenter
        x:parent.width/2 + 15
        Image{
            source:"qrc:/img/cartes/n/bg.png"
            anchors.fill:parent
            fillMode: Image.Stretch
        }

        Text{
            rotation: {originX:width/2;originY:height;angle:90}
            color: "white"
            text:"DRAW"
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }

        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("draw card")
                drawCardBt.qdrawCardBtPressed()
                game.drawCard(0)
            }
        }
    }

    // PLAY CARD & carte active

    Rectangle{
        objectName: "playCardBt"
        //visible: false
        id:playCardBt
        height:150
        width:height*0.65
        radius: 15
        color:"transparent"
        anchors.verticalCenter: parent.verticalCenter
        x:parent.width/2 - width

        CarteBase{
            color:game.curCardColor
            type:game.curCardType
            value:game.curCardValue
        }

        Text{
            rotation: {originX:width/2;originY:height;angle:90}
            text:"PLAY"
            font.pixelSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
        }
        Frame{
            anchors.fill:parent
        }
        signal qplayCardBtPressed(int i);
        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("play card")
                playCardBt.qplayCardBtPressed(list0.currentIndex)
                game.playCard(list0.currentIndex)
            }
        }

    }
}
