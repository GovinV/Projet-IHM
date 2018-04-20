import QtQuick 2.4
import QtQuick.Controls 2.3

PlayerForm {
    id: playerForm
    width: 600
    height: 60

    Connections{
        target: network
        onTmpReady:
        {
            print("non non non");
            print(ready);
            text2.text=ready?qsTr("Prêt"):qsTr("En attente")
            text2.color=ready?"#3ff826":"#b31919"
        }
    }

    property string name: "anonymous"
    property string playerId: "anvsddhfsegdrgsgdrhs"
    property bool ready: false


    onReadyChanged:
    {
        print("oui oui oui");
    }

    Rectangle {
        id: rectangle1
        x: 0
        width: parent.width
        color: "#ffffff"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
    }

    Text {
        id: text1
        y: 17
        width: 410
        height: 43
        color: "#ffffff"
        text: name
        anchors.horizontalCenter: parent.horizontalCenter
        font.bold: true
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.verticalCenterOffset: 1
        anchors.verticalCenter: parent.verticalCenter
        font.pixelSize: 20
    }

    Text {
        id: text2
        x: 519
        y: 10
        width: 73
        height: 40
        color: ready?"#3ff826":"#b31919"
        text: ready?qsTr("Prêt"):qsTr("En attente")
        font.bold: true
        anchors.right: parent.right
        anchors.rightMargin: 8
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        font.pixelSize: 15
    }
}
