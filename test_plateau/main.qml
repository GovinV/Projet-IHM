import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0
import game.backend 1.0
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

    Rectangle{
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        height: 70
        width:200
        color: "white"
        Text{
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.verticalCenter: parent.verticalCenter
            text: "Start Game"
            font.pixelSize: 35
        }
        Frame{
            anchors.fill:parent
        }
        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("click");
                game.start();
            }
        }
    }
}
