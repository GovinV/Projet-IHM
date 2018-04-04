import QtQuick 2.0
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

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

    // bottom player
    Hand{
        anchors.bottom: parent.bottom
        width: parent.width
    }

    //upper player
    Hand{
        transform: Rotation{origin.x : width/2; origin.y: 50; angle: 180}
        anchors.top: parent
        width: parent.width
    }
    RowLayout{
        anchors.centerIn: parent
        Rectangle {
            width: 100
            height: 150
            color:"#333333"
        }
        Rectangle{
            width: 100
            height: 150
            Image{
                anchors.fill:parent
                source: "qrc:/img/cards/0r.png"
            }
        }


    }
}
