import QtQuick 2.12
import QtQuick.Window 2.12

import QtQuick.Controls 1.2
import QtQuick.Layouts 1.12

//import ModelApi 1.0;
import Step2 1.0

ApplicationWindow {
    id: main
    visible: true
    width: 640
    height: 480
    minimumWidth: 320
    minimumHeight: 240
    title: qsTr("Hello World")

    menuBar: Bar{}

    FileDialog {visible: false; id: fd}

    RowLayout {
        width: parent.width
        height: parent.height

        ListBar {
            id: listBar
            Layout.alignment: Qt.AlignTop
            height: main.height
        }
        InstallDiv {
            id: installDiv
            name: Step2.selected ? Step2.selected : "Выберете пункт"

            Layout.fillHeight: true
            Layout.fillWidth: true
            Layout.alignment: Qt.AlignLeft | Qt.AlignTop
        }
    }

    Connections {
        target: Step2
        onMsg: {
            installDiv.textArea.append(txt)
        }
    }

}
