import QtQuick 2.0

Item {
    property string color : "b"
    property int value : 0
    property int type : 0
    property bool showCard: false

    property string str

    anchors.fill:parent

    onShowCardChanged: {
        changecrd(color,type,value);
    }

    function returnPath(cl, tp,vl)
    {
        if(tp === 0){
               return "qrc:/cartes/cartes/"+cl+"/"+vl+".png"
           }
           else if(tp === 1){//+2
              return "qrc:/cartes/cartes/"+cl+"/+2.png"
           }
           else if(tp === 2){//changement de sens
              return "qrc:/cartes/cartes/"+cl+"/s.png"
           }
           else if(tp === 3){//passe
              return "qrc:/cartes/cartes/"+cl+"/p.png"
           }
           else if(tp === 4){//+4
              return "qrc:/cartes/cartes/"+cl+"/+4.png"
           }
           else if(tp === 5){//couleur
              return "qrc:/cartes/cartes/"+cl+"/c.png"
           }
    }

    function changecrd(cl,tp,vl)
    {
        color=cl;
        type=tp;
        value=vl;
        underlayer.source="qrc:/cartes/cartes/"+cl+"/bg.png";
        var src=returnPath(cl,tp,vl);
        figure.source=src;

    }


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
        source:returnPath("b",0,0);

        anchors.fill:parent
        visible: showCard
        fillMode: Image.Stretch
    }
}
