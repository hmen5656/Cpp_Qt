import QtQuick 2.0

Item {
    anchors.fill: parent
    id:mainwin
    property string text_center:"You haven't choosen anything yet"
    Rectangle{
        id:menubar
        width: parent.width
        height: parent.height/15
        color:"purple"

        Mybtn{
            id:btn1
            width:120
            height: parent.height
            textStr: "Show menu"

            //            getMauseArea.onPressed: {
            //                show_box.start()
            //            }
            //            getMauseArea.onReleased: {
            //                hide_box.start()
            //            }
            onBasili: {
                console.log("pressed")
                }

            onBirakildi: {
                console.log("released")
            }
            onBastin:  {
                if(box.state=="visible"){
                    show_box.start();
                    box.state="invisible";
                    mytext.visible =false
                    textStr= "Hide Menu"
                }
                else if(box.state=="invisible"){
                    hide_box.start();
                    box.state="visible";
                    textStr="Show Menu"
                }
                console.log("clicked")
            }
        }
    }
    Rectangle{
        id:box
        width: parent.width*2/3
        height: parent.height-menubar.height
        color:"gray"
        y:menubar.height
        x:-width
        state:"visible"

        PropertyAnimation{
            id:show_box
            target: box
            properties: "x"
            from:-width
            to:0
            duration: 1000
        }
        PropertyAnimation{
            id:hide_box
            target: box
            properties: "x"
            from:0
            to:-width
            duration: 1000
            onStopped:{
                mytext.visible=true
            }
        }

        ListModel{
            id:list_model
            ListElement{
                isim:"huseyin"
                soyad:"men"
                yas:"22"
            }
            ListElement{
                isim:"halil"
                soyad:"ibo"
                yas:"47"
            }
            ListElement{
                isim:"memo"
                soyad:"akgun"
                yas:"31"
            }
            ListElement{
                isim:"sisko"
                soyad:"arik"
                yas:"98"
            }
        }
        ListView{
            id:list
            anchors.fill:parent
            model:list_model
            focus:true
            delegate: Component{
                Item{
                    width: parent.width
                    height: 55

                    Column{
                        Text {
                            text: "Name :"+isim
                            font.pixelSize:15
                        }
                        Text {
                            text: "Surname :"+soyad
                            font.pixelSize:15
                        }
                        Text {
                            text: "Age :"+yas
                            font.pixelSize:15
                        }

                    }
                    MouseArea{
                        anchors.fill:parent
                        onClicked: {
                            list.currentIndex=index;
                        }
                        onDoubleClicked: {
                            text_center=list_model.get(list.currentIndex).isim +"  "+list_model.get(list.currentIndex).soyad
                            hide_box.start()
                            box.state="visible";

                            btn1.textStr="Show Menu"
                        }
                    }
                }
            }
            highlight: Rectangle{
                color: "yellow"
                Text {
                    id:chs
                    anchors.right: parent.right
                    color:"red"
                    text: list_model.get(list.currentIndex).isim+" is choosen "
                }
            }
            onCurrentIndexChanged: console.log(" choosen "+list_model.get(list.currentIndex).isim+" " +list_model.get(list.currentIndex).soyad)
        }
    }


    Text {
        id: mytext
        text: text_center
        visible: false
        anchors.centerIn: parent
        font.pixelSize:  23
    }

}
