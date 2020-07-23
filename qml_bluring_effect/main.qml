import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    visible: true
    width: 640
    height:680
    title: qsTr("Hello World")

    Rectangle{
        id:rootrect
        anchors.fill: parent
        property int value:0
        Image {
            id: myim
            anchors.fill:parent
            source: "myimage.jpg"
        }
        Text {
            id: roottexrt
            anchors.centerIn: parent
            font.pixelSize: parent.height/3
            color:"white"
            text: rootrect.value
            Component.onCompleted: {
                mytmr.start()
            }
        }

       property string st:"arttir"
        Timer{
            id:mytmr
            interval: 1000
            repeat: true
            running: false
            onTriggered: {
                if(rootrect.st=="arttir"){
                    parent.value+=10
                    if(parent.value==100)
                        rootrect.st=="azalt"
                }
                else if(rootrect.st=="azalt"){
                    parent.value-=10
                    if(parent.value==0)
                         rootrect.st=="arttir"
                    }

            }

    }
    LiveBlur{
        id:lvblr
        frsource: rootrect
        blurm: rootrect.value
    }


}
