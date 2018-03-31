import QtQuick 2.10
import QtQuick.Window 2.10

Window {
    visible: true
    width: 1280
    height: 800
    title: qsTr("Hello World")

    Rectangle{
        height: 100 ; width: 200
        x: 100
        y: 200
        color: "#110000"
    }

    Card{
        Image{
            source: "qrc:/img/cards/1r.png"
        }
    }
}
