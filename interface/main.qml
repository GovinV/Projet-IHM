import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtQuick 2.9

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Uno")

    flags: Qt.FramelessWindowHint

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/resources/img/bg.jpg"
    }

    SwipeView
    {
        id: swipeVertical
        currentIndex: 1

        width: parent.width
        height: parent.height-97
        orientation: Qt.Vertical
        interactive: false

        anchors.top: parent.top
        anchors.topMargin: 97

        onCurrentIndexChanged: {
            if(currentIndex==1)
            {
                backLogo.rotation=0;
                returnButton.visible=false;
            }
            else
            {
                backLogo.rotation=-90;
                returnButton.visible=true;
            }
        }

        ServerMenu{
        }

        SwipeView {
            id: swipeHorizontal
            currentIndex: 0
/*
            width: parent.width
            height: parent.height
*/
            onCurrentIndexChanged: {
                if(currentIndex==0)
                    returnButton.visible=false;
                else
                    returnButton.visible=true;
            }

            MainMenu{
            }
            CardEditor{
            }
        }

    }



    MenuBar {
        id: menuBarForm
        x: 0
        y: 0
        width: parent.width
        height: 300
    }

    Button {
        id: returnButton
        visible: false
        y: 691
        width: (parent.width / 2048) * 77 + 100
        height: (parent.width / 2048) * 86
        transformOrigin: Item.Center
        anchors.left: parent.left
        anchors.leftMargin: 30
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 30
        background: rgba(0,0,0,0)

        onClicked: {
            if(swipeVertical.currentIndex==0)
                swipeVertical.setCurrentIndex(1);
            else
                swipeHorizontal.setCurrentIndex(0);
        }

        Image {
            id: backLogo
            width: (window.width / 2048) * 77
            height: (window.width / 2048) * 86
            fillMode: Image.PreserveAspectCrop
            source: "qrc:/resources/img/back.png"
        }

        Text {
            id: text1
            y: 11
            color: "#ffffff"
            text: "Return"
            anchors.verticalCenterOffset: -1
            anchors.left: parent.left
            anchors.leftMargin: (window.width / 2048) * 97
            anchors.verticalCenter: parent.verticalCenter
            font.weight: Font.Bold
            font.family: "Tahoma"
            font.pixelSize: 25
        }
    }


}
