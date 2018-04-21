import QtQuick 2.4
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

MenuBarForm {
    width: 1280
    height: 300

    Connections{
        target: network
    }

    Connections{
        target: settings

        onLoadNickname:
        {
            pseudo.text=mess;
        }
    }

    Rectangle {
        id: backgroundGris
        x: 0
        y: 0
        width:  parent.width
        height: 85
        color: "#272727"
        radius: 0
        border.width: 0
        transformOrigin: Item.TopLeft

        MouseArea {
            id: titleBarMouseRegion
            anchors.fill: parent

            property var clickPos: "1,1"

            onPressed: {
                clickPos  = Qt.point(mouse.x,mouse.y)
            }

            onPositionChanged: {
                var delta = Qt.point(mouse.x-clickPos.x, mouse.y-clickPos.y)
                window.x += delta.x;
                window.y += delta.y;
            }
        }

        Button {
            id: quitButton
            width: 42
            height: 42
            text: qsTr("")
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onHoveredChanged:
            {
                if(hovered)
                {
                    quitBackground.opacity = 1;
                    playSnap.play();
                }
                else
                    quitBackground.opacity = 0;
            }

            onClicked: {
                network.quit();
                playClick.play();
                window.close()
            }

            Rectangle{
               id: quitBackground
               anchors.fill: parent
               color: "white"
               opacity : 0
             }

            Image {
                id: quitLogo
                anchors.fill: parent
                source: "qrc:/resources/img/quit.png"
            }
        }

        Button {
            id: fullButton
            width: 42
            height: 42
            anchors.right: parent.right
            anchors.rightMargin: 42
            anchors.top: parent.top
            anchors.topMargin: 0
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onHoveredChanged:
            {
                if(hovered)
                {
                    fullBackground.opacity = 1;
                    playSnap.play();
                }
                else
                    fullBackground.opacity = 0;
            }


            onClicked: {
                playClick.play();
                if(window.visibility===Window.FullScreen)
                {
                   // settingsForm.fullscreenCheckBox.checked=false;
                    settingsForm.changeFullScreen();
                    window.visibility=Window.Windowed;
                }
                else
                {
                  //  settingsForm.fullscreenCheckBox.checked=true;
                    settingsForm.changeFullScreen();
                    window.visibility=Window.FullScreen;
                }
            }

            Rectangle{
               id: fullBackground
               anchors.fill: parent
               color: "white"
               opacity : 0
             }

            Image {
                id: fullLogo
                anchors.fill: parent
                source: "qrc:/resources/img/full.png"
            }
        }

        Button {
            id: lessButton
            width: 42
            height: 42
            anchors.right: parent.right
            anchors.rightMargin: 84
            anchors.top: parent.top
            anchors.topMargin: 0
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onHoveredChanged:
            {
                if(hovered)
                {
                    lessBackground.opacity = 1;
                    playSnap.play();
                }
                else
                    lessBackground.opacity = 0;
            }

            onClicked: {
                playClick.play();
                    window.visibility=Window.Minimized;
            }

            Rectangle{
               id: lessBackground
               anchors.fill: parent
               color: "white"
               opacity : 0
             }

            Image {
                id: lessLogo
                anchors.fill: parent
                source: "qrc:/resources/img/less.png"
            }
        }

        Button {
            id: optionButton
            width: 48
            height: 48
            anchors.right: parent.right
            anchors.rightMargin: 168
            anchors.verticalCenter: parent.verticalCenter
            background: Rectangle { color: Qt.rgba(0,0,0,0)}

            onHoveredChanged:
            {
                if(hovered)
                {
                    optionBackground.opacity = 1;
                    playSnap.play();
                }
                else
                    optionBackground.opacity = 0;
            }

            onClicked: {
                playClick.play();
                if(settingsRect.isActive)
                    settingsRect.isActive=false;
                else
                    settingsRect.isActive=true;
            }

            Rectangle{
               id: optionBackground
               x: parent.width/4
               y: parent.height/4
               width: parent.width/2
               height: parent.height/2
               color: "white"
               opacity : 0
             }
            Image {
                id: optionLogo
                anchors.fill: parent
                source: "qrc:/resources/img/settings.png"
            }

        }
        Text {
            id: pseudo
            height: 13
            color: "#e98515"
            text: qsTr("Anonymous")
            horizontalAlignment: Text.AlignRight
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 25
            font.bold: true
            font.family: "Tahoma"
            anchors.top: parent.top
            anchors.topMargin: 28
            anchors.right: parent.right
            anchors.rightMargin: 240
            anchors.verticalCenter: parent.verticalCenter

        }

    }

    Rectangle {
        id: borderWhite
        x: 0
        y: 85
        width:  parent.width
        height: (parent.width / 2048) * 12
        color: "#ffffff"
        transformOrigin: Item.TopLeft
    }

    Image {
        id: logo
        x: 0
        y: 0
        width: (parent.width / 2048) * 369
        height: (parent.width / 2048) * 300
        transformOrigin: Item.TopLeft
        source: "qrc:/resources/img/logo.png"
    }



}
