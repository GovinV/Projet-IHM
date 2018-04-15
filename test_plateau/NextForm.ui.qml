import QtQuick 2.4

Item {
    width: 400
    height: 400

    PathView {
        id: pathView
        x: 52
        y: 159
        width: 321
        height: 193
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
        path: Path {
            startX: 296
            startY: 167

            PathCubic {
                x: 164
                y: 78
                control1Y: 111.333
                control2X: 257.333
                control1X: 268.333
                control2Y: 111.333
            }

            PathCubic {
                x: 41
                y: 181
                control1Y: 104.333
                control2X: 61
                control1X: 87.667
                control2Y: 120
            }
        }
        delegate: Column {
            spacing: 5
            Rectangle {
                width: 40
                height: 40
                color: colorCode
                anchors.horizontalCenter: parent.horizontalCenter
            }

            Text {
                x: 5
                text: name
                anchors.horizontalCenter: parent.horizontalCenter
                font.bold: true
            }
        }
    }

    Card {
        id: card
        x: 71
        y: 48
    }
}
