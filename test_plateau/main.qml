import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
//import game.backend 1.0
import game.handmodel 1.0

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Image{
        id:background
        source:"qrc:/img/bg.jpg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
    }

    ListView{
        model:HandModel{
            list:hand_j1
        }

        width: parent.width
        height: parent.height
        orientation:ListView.Horizontal
        delegate: Rectangle{
            Image{
                id: underlayer
                source:"qrc:/img/cartes/"+model.color+"/bg.png"
                anchors.fill:parent
                fillMode: Image.Stretch
            }
            Image{
                id: circle
                source:"qrc:/img/cartes/bg.png"
                anchors.fill:parent
                fillMode: Image.Stretch
            }
            Image{
                id: figure
                source:if(model.type === 0){
                           return "qrc:/img/cartes/"+model.color+"/"+model.value+".png"
                       }else if(model.type === 1){
                           return "qrc:/img/cartes/"+model.color+"/+2.png"
                       }
                anchors.fill:parent
                fillMode: Image.Stretch
            }

            color:"transparent"
            width: 60*2
            height: 90*2

            Text{
                text:model.color
            }
        }
    }

    /*BackEnd{
        id: back
    }

    Text{
        text:back.compteur
    }

    Rectangle{
        id:button1
        x:0
        y:100
        width:100
        height: 100
        color: "white"
        Text{
            text: "+"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                back.compteur++
            }
        }
    }
    Rectangle{
        id:button2
        x:0
        y:200
        width:100
        height: 100
        color: "white"
        Text{
            text: "-"
        }

        MouseArea {
            anchors.fill: parent

            onClicked: {
                back.addObject()
            }
        }
    }*/
}
