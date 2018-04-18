import QtQuick 2.0
import QtQuick.Controls 2.0

Item {
    Rectangle{
        height:100
        width: 100
        Image{
            id:valeur
            anchors.fill: parent
            fillMode: Image.Stretch
        }
        Image{
            id:couleur
            anchors.fill: parent
            fillMode: Image.Stretch
        }
        Image{
            id:type
            anchors.fill: parent
            fillMode: Image.Stretch
        }
    }
}
