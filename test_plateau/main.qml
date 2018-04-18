import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import game.backend 1.0

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    BackEnd{
        id: back
    }

    Image{
        id:background
        source:"qrc:/img/bg.jpg"
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
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
    }

    ListView{
        width:100; height:100;
        x:200
    }
}
