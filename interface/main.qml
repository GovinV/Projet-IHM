import QtQuick.Window 2.10
import QtQuick.Controls 2.2
import QtMultimedia 5.9
import QtQuick 2.9

Window {
    id: window
    visible: true
    width: 1280
    height: 800
    title: qsTr("Uno")

    flags: Qt.FramelessWindowHint

    Connections{
        target: settings
        onLoadVolume:
        {
            playClick.volume=mess;
            playSnap.volume=mess;
        }
    }

    Image {
        id: background
        anchors.fill: parent
        fillMode: Image.PreserveAspectCrop
        source: "qrc:/resources/img/bg.jpg"
    }

    Rectangle {
        id: conteneurCentral
        width: parent.width - settingsForm.width
        height: parent.height-97
        anchors.top: parent.top
        anchors.topMargin: 97
        color: "#00000000"

        SwipeView
        {
            id: swipeVertical
            currentIndex: 1

            orientation: Qt.Vertical
            interactive: false

            anchors.fill: parent

            onCurrentIndexChanged: changedReturnButton()

            SwipeView {
                id: swipeHorizontalServeur
                currentIndex: 0
                interactive: false

                onCurrentIndexChanged: changedReturnButton()

                ServerMenu{
                }
                RoomMenu{
                    id:room
                }
            }

            SwipeView {
                id: swipeHorizontalMenu
                currentIndex: 0
                interactive: false
    /*
                width: parent.width
                height: parent.height
    */
                onCurrentIndexChanged: changedReturnButton()

                MainMenu{
                }
                CardEditor{
                }
            }

        }
    }

    Settings
    {
        id: settingsForm
        width: isActive?300:0
        height: parent.height-90
        anchors.top: parent.top
        anchors.topMargin: 90
        anchors.right: parent.right
        anchors.rightMargin: 0
        visible: isActive

        property bool isActive: false

    }

    MenuBar {
        id: menuBarForm
        x: 0
        y: 0
        width: parent.width
        height: 300
    }

    function changedReturnButton()
    {
        if(swipeVertical.currentIndex==1)
        {
            backLogo.rotation=0;
            if(swipeHorizontalMenu.currentIndex==0)
                returnButton.visible=false;
            else
                returnButton.visible=true;
        }
        else
        {
            returnButton.visible=true;
            if(swipeHorizontalServeur.currentIndex==0)
            {
                backLogo.rotation=-90;
            }
            else
            {
                backLogo.rotation=0;
            }
        }

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
        background: Rectangle { color: Qt.rgba(0,0,0,0)}

        onHoveredChanged:
        {
            if(hovered)
                playSnap.play();
        }

        onClicked:{
            playClick.play();
            if(swipeVertical.currentIndex==0)
            {
                if(swipeHorizontalServeur.currentIndex==0)
                    swipeVertical.currentIndex=1;
                else
                {
                    network.quitRoom();
                    network.roomList();
                    swipeHorizontalServeur.currentIndex=0;
                }
            }
            else
                swipeHorizontalMenu.currentIndex=0;
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

    SoundEffect {
        id: playClick
        volume: 1
        source: "qrc:/sons/sons/click.wav"
    }
    SoundEffect {
        id: playSnap
        source: "qrc:/sons/sons/snap.wav"
    }

}
