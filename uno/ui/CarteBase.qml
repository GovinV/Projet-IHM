import QtQuick 2.0

Item {
    property string color
    property int value
    property int type
    anchors.fill:parent
    Image{
        id: underlayer
        source:"qrc:/img/cartes/"+color+"/bg.png"
        anchors.fill:parent
        fillMode: Image.Stretch
    }
    Image{
        id: circle
        source:"qrc:/img/cartes/bg.png"
        anchors.fill:parent
        fillMode: Image.Stretch
    }
    Image{
        id: figure
        source:if(type === 0){//numero
                   return "qrc:/img/cartes/"+color+"/"+value+".png"
               }
               else if(type === 1){//+2
                   return "qrc:/img/cartes/"+color+"/+2.png"
               }
               else if(type === 2){//changement de sens
                   return "qrc:/img/cartes/"+color+"/s.png"
               }
               else if(type === 3){//passe
                   return "qrc:/img/cartes/"+color+"/p.png"
               }
               else if(type === 4){//+4
                   return "qrc:/img/cartes/"+color+"/+4.png"
               }
               else if(type === 5){//couleur
                   return "qrc:/img/cartes/"+color+"/c.png"
               }

        anchors.fill:parent
        fillMode: Image.Stretch
    }
}
