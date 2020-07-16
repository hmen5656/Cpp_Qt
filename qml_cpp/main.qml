import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: window
    visible: true
    width: 400
    height: 110


    Timer{
        id:timer1
        running: false
        interval: 1000
        repeat: true

        onTriggered: {
            if(myrect.state=="def"){
                myrect.state="left"
            }
            else{
                myrect.state="def"
            }
        }


    }

    Rectangle{
        id:myrect
        width: 200
        height: 110
        x:0//window.width/2-width/2
        y: 0//window.height/2-height/2
        color:"orange"
        state: "def"
        radius:10
    Text {
        id: mytext
        text: qsTr("press me")
        anchors.centerIn: parent
        horizontalAlignment: mytext.AlignHCenter
        verticalAlignment: mytext.AlignVCenter
    }
    MouseArea{
        id:mA
        anchors.fill:parent
        onClicked:{
            receiver.get_someting("my name is huseyin");
            timer1.start()


            //movetext.start()
        }
    }
    states: [

        State {
            name: "def"
            PropertyChanges {
                target: myrect
                color:"orange"
                x:0
                y:0
                width:200
                height:110

            }
        },State {
            name: "left"
            PropertyChanges {
                target: myrect
                color:"red"
                x:300
                y:23
                width:100
                height:55


            }
        }

            ]

        transitions: [ //burda ise gecisleri duzenleyebiliyoruz ayri ayri propert yazmadan

            Transition {
                from: "left"
                to: "def"
                ParallelAnimation{//def ten stateye gecerkenki degisiklikleri algilayip animasyon yapiyor
                    NumberAnimation { properties: "x,y,width,height" ;duration:500 ; easing.type: Easing.InOutBack }
                    ColorAnimation{ duration:500}
                }

            },
            Transition { // def ten left e gecis varsa bu gecisi kurguluyor verdigimiz parametreler ile
                from: "def"
                to: "left"
                ParallelAnimation{//def ten stateye gecerkenki degisiklikleri algilayip animasyon yapiyor
                    NumberAnimation { properties: "x,y,width,height" ;duration:500 ; easing.type: Easing.InOutBack }
                    ColorAnimation{ duration:500}
                }

            }



            ]



    }


//    PropertyAnimation{
//        id:movetext
//        target: myrect
//        properties: "x,y"
//        easing.type: Easing.Linear
//        to:myrect.x+50
//        duration: 2000
//        onStarted: {
//            changeclr.start()
//            }
//    }
//    PropertyAnimation{
//        id:changeclr
//        target: myrect
//        properties: "color"
//        to:Qt.rgba(myrect.x/200,myrect.x/100+5,myrect.y/100,1)
//        duration: 2000
//    }


}
