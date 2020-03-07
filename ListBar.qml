import QtQuick 2.12
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.0

//import ModelApi 1.0;
//import PkgApi 1.0;

//import Util 1.0
//import PkgApi 1.0

import InstallList 1.0
import Step2 1.0

ColumnLayout {
    spacing: 0
    signal changename(string name)

    ListView {
        width: 180
        height: parent.height
//        clip: false
        Layout.fillHeight: true
        Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        Layout.bottomMargin: 0
        id: navigation

        anchors.top: main.bottom
        anchors.bottom: main.bottom

        model: Step2

        delegate: Button {
            width: parent.width
            text: `${index} ${name}`
            palette { button: statusColor }
            onClicked: {
                console.log("select " + name )
                console.log("script " + script )
                console.log("pkg: " + pkg )
                console.log("statusColor: " + statusColor )

                navigation.currentIndex = index
                Step2.setN(index);
            }
            font.bold: ListView.isCurrentItem
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
