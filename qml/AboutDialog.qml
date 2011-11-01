import QtQuick 1.0
import com.nokia.meego 1.0

QueryDialog {
    id: aboutDialog

    titleText: "mac2wepkey by Iktwo " + "1.0.0"
    icon: "qrc:/icons/applogo.png"
    message: qsTr("Test the security of your huawei modem, if you enter your modem's mac and it shows your wepkey, you should consider changing it. <br><br> &copy; Iktwo 2011<br><br>Bugs/Comments <br> Send me an <a href=\"mailto:elmaildeliktwo@gmail.com\"> email</a>")
}
