import QtQuick 2.0
import QtQuick.Controls 2.0

Item{
    property var listdata

    height: 150
    width: 150*0.65

    Rectangle{
        anchors.fill:parent
        Image{
            id: underlayer
            source:"qrc:/img/cartes/"+model.color+"/bg.png"
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
            source:if(model.type === 0){//numero
                       return "qrc:/img/cartes/"+model.color+"/"+model.value+".png"
                   }
                   else if(model.type === 1){//+2
                       return "qrc:/img/cartes/"+model.color+"/+2.png"
                   }
                   else if(model.type === 2){//changement de sens
                       return "qrc:/img/cartes/"+model.color+"/s.png"
                   }
                   else if(model.type === 3){//passe
                       return "qrc:/img/cartes/"+model.color+"/p.png"
                   }
                   else if(model.type === 4){//+4
                       return "qrc:/img/cartes/"+model.color+"/+4.png"
                   }
                   else if(model.type === 5){//couleur
                       return "qrc:/img/cartes/"+model.color+"/c.png"
                   }

            anchors.fill:parent
            fillMode: Image.Stretch
        }
        Text{
            text:index
        }
        Text{
            text: parent.parent.ListView.isCurrentItem ? "selected" : ""
        }

        color:"transparent"

        //scale: parent.ListView.isCurrentItem ? 1.2 : 1
        //Behavior on scale { NumberAnimation { duration: 100 } }
        //y: parent.ListView.isCurrentItem ? -200 : 0
        //Behavior on x { NumberAnimation { duration: 100 } }

    }
    MouseArea{

        anchors.fill:parent
        onClicked: {
            listdata.currentIndex = index
            console.log("select");
        }
    }

}
