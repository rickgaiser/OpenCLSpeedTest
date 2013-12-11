import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Window 2.0
import QtQuick.Layouts 1.0


Item {
    width: 400
    height: 260

    Column {
        anchors.fill: parent
        spacing: 10
        anchors.margins: 10

        ComboBox {
            width: parent.width

            model: opencl.deviceList
            onCurrentIndexChanged: {
                opencl.deviceIndexChanged(currentIndex)
            }

        }

        TextArea {
            width: parent.width
            height: 70
            text: opencl.deviceData
            readOnly: true
        }

        GridLayout {
            width: parent.width
            columnSpacing: 20

            id: grid
            columns: 3
            // Row 1
            Item { Layout.fillWidth: true; }
            Text { Layout.fillWidth: true; text: "Read (GB/s)" }
            Text { Layout.fillWidth: true; text: "Write (GB/s)" }

            // Row 2
            Text { Layout.alignment: Qt.AlignVCenter | Qt.AlignRight; text: "Global" }
            TextInputCustom { text: opencl.globalReadSpeed.toFixed(2) }
            TextInputCustom { text: opencl.globalWriteSpeed.toFixed(2) }

            // Row 3
            Text { Layout.alignment: Qt.AlignVCenter | Qt.AlignRight; text: "Local" }
            TextInputCustom { text: opencl.localReadSpeed.toFixed(2) }
            TextInputCustom { text: opencl.localWriteSpeed.toFixed(2) }
        }

        Button {
            anchors.right: parent.right
            text: "Start"
            onClicked: {
                opencl.startTest()
            }
        }
    }

}
