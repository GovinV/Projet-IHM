import QtQuick 2.0

Flipable {
    id: card

    //property bool flipped: true

    width: 70
    height: 100

    // front value is set on hand initialisation

    back: Image{
        id: backImg
        anchors.fill:parent
        source: "qrc:/img/cards/dos.png"
    }

    transform: Rotation{
        id: rotation
        origin.x: card.width/2
        origin.y: card.height/2
        axis.x: 0; axis.y: 1; axis.z: 0
        angle: 0
    }

    states: State{
        name: "back"
        PropertyChanges {
            target: rotation
            angle: 180
        }
        when: card.flipped
    }

    transitions: Transition {
        NumberAnimation {
            target: rotation
            property: "angle"
            duration: 500
            easing.type: Easing.InOutQuad
        }
    }
    MouseArea{
        anchors.fill: parent
        onClicked: card.flipped = !card.flipped
    }
}
