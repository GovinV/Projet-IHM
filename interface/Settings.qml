import QtQuick 2.9
import QtQuick.Controls 2.3
import QtQuick.Window 2.3

Window {
    id: window
    visible: true
    width: 200
    height: 500

    flags: Qt.FramelessWindowHint

    Rectangle {
        id: rectangle
        anchors.fill:parent
        color: "#272727"
    }

    Rectangle {
        id: rectangleborder
        x: 0
        y: 85
        width:  parent.width
        height: 13
        color: white
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

            property variant clickPos: "1,1"

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
            background: rgba(0,0,0,0)

            onClicked: {

                window.close()
            }

            Rectangle{
               id: quitBackground
               anchors.fill: parent
               color: white
               opacity : 0
             }
             onHoveredChanged: hovered ? quitBackground.opacity = 1 : quitBackground.opacity = 0;

            Image {
                id: quitLogo
                anchors.fill: parent
                source: "qrc:/resources/img/quit.png"
            }
        }
    }

}
