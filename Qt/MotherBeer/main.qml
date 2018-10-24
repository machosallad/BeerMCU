import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import QtQuick.Layouts 1.1

ApplicationWindow {
    id: applicationWindow1
    title: qsTr("MotherBeer")
    width: 350
    height: 500
    visible: true

    menuBar: MenuBar {
        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&Open")
                onTriggered: messageDialog.show(qsTr("Open action triggered"));
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered: Qt.quit();
            }
        }
    }

    Button{
        id: isRunningBtn
        text: backend.isRunnning ? "Stop server" : "Start server"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.left: parent.left
        onClicked: backend.startStopServer()
    }

    Button{
        anchors.left: isRunningBtn.right
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        text: backend.isDiscovering ? "Stop discover" : "Start discover"
        onClicked: backend.startStopDiscover()
    }

    Text
    {
        text: "IN DISCOVER MODE - NO VALUES WILL BE STORED"
        visible: backend.isDiscovering
        font.pixelSize: 12
        anchors.bottomMargin: 5
        anchors.leftMargin: 5
        anchors.left: parent.left
        anchors.bottom: isRunningBtn.top
    }

    ColumnLayout
    {
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 5
        spacing: 5.6
        RowLayout
        {
            id: userRowOne
            Text{
                text:"User #1"
            }

            TextField
            {
                id: idOneNameField
                width: 100
                onTextChanged: idOneSetNameButton.enabled = true
            }

            Button{
                id: idOneSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrOne.setUserName(idOneNameField.text);
                    enabled = false;
                    idOneNameField.focus = false;
                }
            }

            Rectangle{
                id: idOne
                height: 20
                width: height
                color: usrOne.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idOneText
                    text: usrOne.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrOne.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowTwo
            Text{
                text:"User #2"
            }

            TextField
            {
                id: idTwoNameField
                width: 100
                onTextChanged: idTwoSetNameButton.enabled = true
            }

            Button{
                id: idTwoSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrTwo.setUserName(idTwoNameField.text);
                    enabled = false;
                    idTwoNameField.focus = false;
                }
            }

            Rectangle{
                id: idTwo
                height: 20
                width: height
                color: usrTwo.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idTwoText
                    text: usrTwo.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrTwo.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowThree
            Text{
                text:"User #3"
            }

            TextField
            {
                id: idThreeNameField
                width: 100
                onTextChanged: idThreeSetNameButton.enabled = true
            }

            Button{
                id: idThreeSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrThree.setUserName(idThreeNameField.text);
                    enabled = false;
                    idThreeNameField.focus = false;
                }
            }

            Rectangle{
                id: idThree
                height: 20
                width: height
                color: usrThree.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idThreeText
                    text: usrThree.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrThree.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowFour
            Text{
                text:"User #4"
            }

            TextField
            {
                id: idFourNameField
                width: 100
                onTextChanged: idFourSetNameButton.enabled = true
            }

            Button{
                id: idFourSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrFour.setUserName(idFourNameField.text);
                    enabled = false;
                    idFourNameField.focus = false;
                }
            }

            Rectangle{
                id: idFour
                height: 20
                width: height
                color: usrFour.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idFourText
                    text: usrFour.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrFour.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowFive
            Text{
                text:"User #5"
            }

            TextField
            {
                id: idFiveNameField
                width: 100
                onTextChanged: idFiveSetNameButton.enabled = true
            }

            Button{
                id: idFiveSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrFive.setUserName(idFiveNameField.text);
                    enabled = false;
                    idFiveNameField.focus = false;
                }
            }

            Rectangle{
                id: idFive
                height: 20
                width: height
                color: usrFive.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idFiveText
                    text: usrFive.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrFive.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowSix
            Text{
                text:"User #6"
            }

            TextField
            {
                id: idSixNameField
                width: 100
                onTextChanged: idSixSetNameButton.enabled = true
            }

            Button{
                id: idSixSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrSix.setUserName(idSixNameField.text);
                    enabled = false;
                    idSixNameField.focus = false;
                }
            }

            Rectangle{
                id: idSix
                height: 20
                width: height
                color: usrSix.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idSixText
                    text: usrSix.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrSix.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowSeven
            Text{
                text:"User #7"
            }

            TextField
            {
                id: idSevenNameField
                width: 100
                onTextChanged: idSevenSetNameButton.enabled = true
            }

            Button{
                id: idSevenSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrSeven.setUserName(idSevenNameField.text);
                    enabled = false;
                    idSevenNameField.focus = false;
                }
            }

            Rectangle{
                id: idSeven
                height: 20
                width: height
                color: usrSeven.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idSevenText
                    text: usrSeven.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrSeven.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowEight
            Text{
                text:"User #8"
            }

            TextField
            {
                id: idEightNameField
                width: 100
                onTextChanged: idEightSetNameButton.enabled = true
            }

            Button{
                id: idEightSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrEight.setUserName(idEightNameField.text);
                    enabled = false;
                    idEightNameField.focus = false;
                }
            }

            Rectangle{
                id: idEight
                height: 20
                width: height
                color: usrEight.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idEightText
                    text: usrEight.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrEight.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowNine
            Text{
                text:"User #9"
            }

            TextField
            {
                id: idNineNameField
                width: 100
                onTextChanged: idNineSetNameButton.enabled = true
            }

            Button{
                id: idNineSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrNine.setUserName(idNineNameField.text);
                    enabled = false;
                    idNineNameField.focus = false;
                }
            }

            Rectangle{
                id: idNine
                height: 20
                width: height
                color: usrNine.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idNineText
                    text: usrNine.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrNine.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowTen
            Text{
                text:"User #10"
            }

            TextField
            {
                id: idTenNameField
                width: 100
                onTextChanged: idTenSetNameButton.enabled = true
            }

            Button{
                id: idTenSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrTen.setUserName(idTenNameField.text);
                    enabled = false;
                    idTenNameField.focus = false;
                }
            }

            Rectangle{
                id: idTen
                height: 20
                width: height
                color: usrTen.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idTenText
                    text: usrTen.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrTen.light ? "blue" : "orange"
            }
        }

        RowLayout
        {
            id: userRowEleven
            Text{
                text:"User #11"
            }

            TextField
            {
                id: idElevenNameField
                width: 100
                onTextChanged: idElevenSetNameButton.enabled = true
            }

            Button{
                id: idElevenSetNameButton
                text: "Set"
                enabled: false
                onClicked:
                {
                    usrEleven.setUserName(idElevenNameField.text);
                    enabled = false;
                    idElevenNameField.focus = false;
                }
            }

            Rectangle{
                id: idEleven
                height: 20
                width: height
                color: usrEleven.connected ? "green" : "red"
                Text{
                    anchors.centerIn: parent
                    id: idElevenText
                    text: usrEleven.counter
                }
            }

            Rectangle{
                height: 20
                width: height
                color: usrEleven.light ? "blue" : "orange"
            }
        }
    }

    statusBar: StatusBar
    {
    RowLayout {
        anchors.fill: parent
        Text {
            id: serverRunningText
            text: backend.isRunnning ? "Server Running" : "Server not running"
        }
        Text {
            id: dbText
            text: backend.dbManager.dbPath
        }
    }
}

}
