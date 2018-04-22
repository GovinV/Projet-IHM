import QtQuick 2.0

Item {
    property string color
    property int value
    property int type
    property bool showCard: true
    anchors.fill:parent

    Image{
        id: underlayer
        source:"qrc:/cartes/cartes/"+color+"/bg.png"
        anchors.fill:parent
        visible: showCard
        fillMode: Image.Stretch
    }
    Image{
        id: circle
        source:showCard?"qrc:/cartes/cartes/bg.png":"qrc:/cartes/cartes/dos.png"
        anchors.fill:parent
        fillMode: Image.Stretch
    }
    Image{
        id: figure
        source:if(type === 0){//numero
                   return "qrc:/cartes/cartes/"+color+"/"+value+".png"
               }
               else if(type === 1){//+2
                   return "qrc:/cartes/cartes/"+color+"/+2.png"
               }
               else if(type === 2){//changement de sens
                   return "qrc:/cartes/cartes/"+color+"/s.png"
               }
               else if(type === 3){//passe
                   return "qrc:/cartes/cartes/"+color+"/p.png"
               }
               else if(type === 4){//+4
                   return "qrc:/cartes/cartes/"+color+"/+4.png"
               }
               else if(type === 5){//couleur
                   return "qrc:/cartes/cartes/"+color+"/c.png"
               }

        anchors.fill:parent
        visible: showCard
        fillMode: Image.Stretch
    }
}
