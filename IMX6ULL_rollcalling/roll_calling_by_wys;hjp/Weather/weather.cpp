#include "Weather/weather.h"
#include "ui_weather.h"

Weather::Weather(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Weather)
{
    ui->setupUi(this);
    this->resize(1024,600);
    request.setUrl(QUrl("http://gfeljm.tianqiapi.com/api?unescape=1&version=v9&appid=82455931&appsecret=X2Z4OvM5"));
    netManager.get(request);
    connect(&netManager,SIGNAL(finished(QNetworkReply *)),this,SLOT(getWeatherInfo(QNetworkReply *)));
    //qDebug()<<TransDataToWeek("2024-03-13");
    ui->groupBox_Total->setObjectName("MainGroupBox");
    ui->groupBox_Total->setStyleSheet("#MainGroupBox{background-image:url(':/weather/Weather/images/UI2.png');}");
}

Weather::~Weather()
{
    delete ui;
}

/* 将日期转换为星期  */
QString Weather::TransDataToWeek(QString Data)
{
    QDate date;
    date =  QDate::fromString(Data,"yyyy-MM-dd");
    int week = date.dayOfWeek();
    switch (week) {
    case 1:
        return "星期一";
    case 2:
        return "星期二";
    case 3:
        return "星期三";
    case 4:
        return "星期四";
    case 5:
        return "星期五";
    case 6:
        return "星期六";
    case 7:
        return "星期七";
    default:
        return "星期零";
    }
}

/* 将 xx-xx 转换为xx月xx日  */
QString Weather::TransDataToMyData(QString Data)
{
    QString MM = Data.split("-").at(1);
    QString DD = Data.split("-").at(2);
    return QString("%1月%2日").arg(MM).arg(DD);
}

/* 拼接显示 昼夜温度  */
QString Weather::TransTempToStr(QString tmpDay, QString tmpNight)
{
    return QString("%1~%2 ℃").arg(tmpDay).arg(tmpNight);
}

/* 根据天气选择对应图片  */
QString Weather::SelectWeatherImg(QString WeatherDes)
{
    return QString(":/weather/Weather/images/%1.png").arg(WeatherDes);
}

void Weather::updateInfo()
{
    netManager.get(request);
}


/* 根据网络请求结果解析得到天气数据  并转换为合适格式后显示  */
void Weather::getWeatherInfo(QNetworkReply *reply)
{
    QByteArray bytes = reply->readAll();
    int num = bytes.size();
        //qDebug()<<bytes;
    QJsonDocument doc = QJsonDocument::fromJson(bytes);
    if(!doc.isObject()){
        qDebug()<<"Netjson not an jsonObject!";
        QMessageBox::warning(this,"Warning","获取数据失败！请检查网络");
        this->hide();
        return;
    }
    if(num<60)
    {
        QMessageBox::warning(this,"Warning","天气API过期，请更新API");
        return;
    }
    QJsonObject obj = doc.object();
   // QString cityId = obj.value("cityid").toString();
    cityName = obj.value("city").toString();
    UpdateTime = obj.value("update_time").toString();
    QJsonArray arrays = obj.value("data").toArray();
    QJsonObject weather0 = arrays[0].toObject();
    QJsonObject weather1 = arrays[1].toObject();
    QJsonObject weather2 = arrays[2].toObject();
    QJsonObject weather3 = arrays[3].toObject();
    QJsonObject weather4 = arrays[4].toObject();
    for(int i=0;i<7;i++)
    {
        weather_data.append(arrays[i].toObject().value("date").toString());
        weather_wea.append(arrays[i].toObject().value("wea").toString());
        weather_tem_day.append(arrays[i].toObject().value("tem_day").toString());
        weather_tem_night.append(arrays[i].toObject().value("tem_night").toString());
        weather_win.append(arrays[i].toObject().value("win").toString());
        weather_win_speed.append(arrays[i].toObject().value("win_speed").toString());
        weather_wea_img.append(arrays[i].toObject().value("wea_img").toString());
    }

    ui->label_day1_data->setText(TransDataToMyData(weather_data.at(1)));
    ui->label_day2_data->setText(TransDataToMyData(weather_data.at(2)));
    ui->label_day3_data->setText(TransDataToMyData(weather_data.at(3)));
    ui->label_day4_data->setText(TransDataToMyData(weather_data.at(4)));

    ui->label_day1_week->setText(TransDataToWeek(weather_data.at(1)));
    ui->label_day2_week->setText(TransDataToWeek(weather_data.at(2)));
    ui->label_day3_week->setText(TransDataToWeek(weather_data.at(3)));
    ui->label_day4_week->setText(TransDataToWeek(weather_data.at(4)));

    ui->label_day1_des->setText(weather_wea.at(1));
    ui->label_day2_des->setText(weather_wea.at(2));
    ui->label_day3_des->setText(weather_wea.at(3));
    ui->label_day4_des->setText(weather_wea.at(4));

    ui->label_day1_win->setText(weather_win.at(1));
    ui->label_day2_win->setText(weather_win.at(2));
    ui->label_day3_win->setText(weather_win.at(3));
    ui->label_day4_win->setText(weather_win.at(4));

    ui->label_day1_winSpeed->setText(weather_win_speed.at(1));
    ui->label_day2_winSpeed->setText(weather_win_speed.at(2));
    ui->label_day3_winSpeed->setText(weather_win_speed.at(3));
    ui->label_day4_winSpeed->setText(weather_win_speed.at(4));

    ui->label_day1_tmp->setText(TransTempToStr(weather_tem_day.at(1),weather_tem_night.at(1)));
    ui->label_day2_tmp->setText(TransTempToStr(weather_tem_day.at(2),weather_tem_night.at(2)));
    ui->label_day3_tmp->setText(TransTempToStr(weather_tem_day.at(3),weather_tem_night.at(3)));
    ui->label_day4_tmp->setText(TransTempToStr(weather_tem_day.at(4),weather_tem_night.at(4)));

    QPixmap pixmap;

    ui->label_day1_img->setScaledContents(true);
    ui->label_day2_img->setScaledContents(true);
    ui->label_day3_img->setScaledContents(true);
    ui->label_day4_img->setScaledContents(true);
    pixmap.load(SelectWeatherImg(weather_wea_img.at(1)));
    pixmap.scaled(ui->label_day1_img->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation);
    ui->label_day1_img->setPixmap(pixmap);
    pixmap.load(SelectWeatherImg(weather_wea_img.at(2)));
    ui->label_day2_img->setPixmap(pixmap);
    pixmap.load(SelectWeatherImg(weather_wea_img.at(3)));
    ui->label_day3_img->setPixmap(pixmap);
    pixmap.load(SelectWeatherImg(weather_wea_img.at(4)));
    ui->label_day4_img->setPixmap(pixmap);

    ui->label_now_img->setScaledContents(true);
    pixmap.load(SelectWeatherImg(weather_wea_img.at(0)));
    ui->label_now_img->setPixmap(pixmap);
    ui->label_now_des->setText(weather_wea.at(0));
    ui->label_now_win->setText(weather_win.at(0));
    ui->label_now_winSpeed->setText(weather_win_speed.at(0));
    ui->label_now_tmp->setText(weather_tem_day.at(0));

    ui->label_Time->setText(UpdateTime);
    ui->label_location->setText(cityName);

}


void Weather::on_pushButton_clicked()
{
    updateInfo();
}

void Weather::on_pushButton_2_clicked()
{
    this->hide();
}
