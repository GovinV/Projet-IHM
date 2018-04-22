import QtQuick 2.7
import QtQuick.Window 2.1
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.0

import game.backend 1.0
import game.handmodel 1.0


GameForm {
    id: gameForm
    width: 1280
    height: 800

    property bool myturn: false

    Connections{
        target: game
        onCurCardChange:
        {
            print("onCurCardChange");
            playCardBt.changecrd(cl, index, value,0);
        }
        onMyTurn:
        {
            print("onMyTurn");
            myturn=true;
        }
        onPlayCardOk:
        {
            print("onPlayCardOk");
            gameForm.myturn=false;
        }

    }

    function startGame()
    {
       game.start();
    }

    // PLAYER 0
    ListView{
        id:list0
        //STYLE
        width:parent.width-200
        height:150
        //interactive:false
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5;
        anchors.left: parent.left
        anchors.leftMargin:200
        orientation:ListView.Horizontal
        //spacing: -50
        //clip:true;

        //DATA
        model:HandModel{
            list:hand_j0
        }
        delegate:Rectangle{
            width: (list0.width/list0.count>150*0.65)?150*0.65:list0.width/list0.count
            Carte{listdata:list0
            show:true}
        }

    }

    // PLAYER 1
    ListView{
        rotation: {originX:width/2;originY:height/2;angle:180}
        id:list1

        //STYLE
        width:parent.width/2
        height:150
        anchors.horizontalCenter: parent.horizontalCenter
        highlightRangeMode: ListView.StrictlyEnforceRange
        //interactive:false
        anchors.left: parent.left
        anchors.leftMargin:parent.width/4
        anchors.top: parent.top
        anchors.topMargin: -75
        orientation:ListView.Horizontal
        //spacing: -50
        //clip:true;

        interactive: false

        //DATA
        model:HandModel{
            list:hand_j1
        }
        delegate:Rectangle{
            width: list1.width/list1.count
            Carte{listdata:list1}
        }
    }

    ListView{
        rotation: {originX:width/2;originY:height/2;angle:180}
        id:list2

        //STYLE
        width:150*0.65
        height:parent.height/2
        //interactive:false
        anchors.left: parent.left
        anchors.leftMargin:-75*0.65
        anchors.top: parent.top
        anchors.topMargin: parent.height/4
        //spacing: -50
        //clip:true;

        interactive: false

        //DATA
        model:HandModel{
            list:hand_j2
        }
        delegate:Rectangle{
            height:list2.height/list2.count
            Carte{listdata:list2
                rotation: 90}
        }
    }

    ListView{
        rotation: {originX:width/2;originY:height/2;angle:180}
        id:list3

        //STYLE
        width:150*0.65
        height:parent.height/2
        //interactive:false
        anchors.right: parent.right
        anchors.rightMargin:-75*0.65
        anchors.top: parent.top
        anchors.topMargin: parent.height/4
        //spacing: -50
        //clip:true;

        interactive: false

        //DATA
        model:HandModel{
            list:hand_j3
        }
        delegate:Rectangle{
            height:list3.height/list3.count
            Carte{listdata:list3
                rotation: 90}
        }
    }

    // START GAME BUTTON

    // UNO !
    Button{
        id:unobtn

        height:gameForm.width/1280*100
        width:(gameForm.width/1280)*100
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.horizontalCenterOffset: playCardBt.width+30

        background:Rectangle{
            anchors.fill:parent
            color:"#00000000"
            Image {
                id: name
                anchors.fill:parent
                source: "qrc:/resources/img/uno.png"
            }
        }
    }


    Button{
        id:drawCardBt
        height:gameForm.width/1280*164
        width:gameForm.width/1280*108
        anchors.left: parent.left
        anchors.leftMargin:gameForm.width/1280*200
        anchors.top: parent.top
        anchors.topMargin: gameForm.width/1280*100
        rotation: -35

        background: Rectangle{
            color: "#00000000"
            Image{
                source:"qrc:/cartes/cartes/pioche.png"
                anchors.fill:parent
                fillMode: Image.Stretch
            }
        }
        onClicked: {
            console.log("draw card")
        }
    }
    Rectangle{
        id:playCardBt2
        height:gameForm.width/1280*150
        width:(gameForm.width/1280)*150*0.65
        radius: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"transparent"
        rotation: -5
        visible:false;

        function changecrd(cl, tp, vl,rt)
        {
            playCardBt2.visible=true;
            playCardBt2.rotation=rt;
            card1.changecrd(cl,tp,vl);
        }

        CarteBase{
            id: card3
            showCard: true
        }
    }
    // PLAY CARD & carte active
    Rectangle{
        id:playCardBt1
        height:gameForm.width/1280*150
        width:(gameForm.width/1280)*150*0.65
        radius: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"transparent"
        rotation: 10
        visible:false;

        function changecrd(cl, tp, vl,rt)
        {
            visible=true;
            playCardBt2.changecrd(card2.color,card2.type,card2.value,playCardBt1.rotation)
            playCardBt1.rotation=rt;
            card1.changecrd(cl,tp,vl);
        }

        CarteBase{
            id: card2
            showCard: true
        }
    }

    Rectangle{
        id:playCardBt
        height:gameForm.width/1280*150
        width:(gameForm.width/1280)*150*0.65
        radius: 15
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"transparent"
        rotation: 0

        function changecrd(cl,tp,vl,rt)
        {
            playCardBt1.changecrd(card1.color,card1.type,card1.value,playCardBt.rotation)
            playCardBt.rotation=Math.floor(Math.random() * Math.floor(30))-15;
            card1.changecrd(cl,tp,vl);
        }

        CarteBase{
            id: card1
            color:"b"
            type:0
            value:0
            showCard: true
        }
    }

    Rectangle{
        id:changeColor
        height:gameForm.width/1280*300
        width:gameForm.width/1280*300
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter
        color:"#00000000"

        visible: false

        Image {
            anchors.fill:parent
            source: "qrc:/cartes/cartes/color.png"
        }

        MouseArea{
            anchors.fill:parent
            onClicked: {
                console.log("change color ! x:" + mouse.x + " y:" +mouse.y);
                if(mouse.x<width/2)
                {
                    if(mouse.y<height/2)
                        print("bleu");
                    else
                        print("jaune");
                }
                else
                {
                    if(mouse.y<height/2)
                        print("vert");
                    else
                        print("rouge");
                }
                changeColor.visible=false;
            }
        }
    }
}
