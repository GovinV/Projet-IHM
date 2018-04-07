import QtQuick 2.4

CardForm {

    property string couleur: "r"
    property string type: "+2"
    property string style: "none"

    Image {
        id: fond
        anchors.fill: parent
        source: "qrc:/cartes/cartes/"+ couleur+"/bg.png"
    }

    Image {
        id: texture
        anchors.fill: parent
        source: "qrc:/cartes/cartes/style/"+ style +".png"
        visible: style==="none"?false:true
    }

    Image {
        id: contour
        anchors.fill: parent
        source: "qrc:/cartes/cartes/bg.png"
    }

    Image {
        id: symbole
        anchors.fill: parent
        source: "qrc:/cartes/cartes/"+ couleur+"/"+ type +".png"
    }
}
