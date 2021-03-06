package time;

import org.joda.time.DateTime;
import org.joda.time.DateTimeZone;
import org.joda.time.Period;
import org.joda.time.format.DateTimeFormat;
import org.joda.time.format.DateTimeFormatter;
import org.joda.time.format.ISODateTimeFormat;

import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Properties;
import java.util.Set;
import java.util.TimeZone;

import static java.lang.System.*;

/**
 * Created by saligia on 17-7-20.
 */
public class DateTimeGet {


    public static void timeInZone() {


    }

    // ISO Test
    public static void isoTime(){
        DateTimeZone.setDefault(DateTimeZone.UTC);
        out.println(ISODateTimeFormat.basicDateTime().print(1l));
    }


    public static void timePeriod(){

        DateTime time = DateTime.parse("2017-08-01", DateTimeFormat.forPattern("yyyy-MM-dd"));

        Period period = Period.parse("P5D");
        period = period.plusDays(1);

        out.println(period);

        time = time.plus(period);
        //time = time.plusDays(1);
        out.println(time);
    }


    public static void timeTimestame(){
        DateTime time1 = DateTime.parse("2017-08-01", DateTimeFormat.forPattern("yyyy-MM-dd"));
        DateTime time2 = DateTime.parse("2017-08-02", DateTimeFormat.forPattern("yyyy-MM-dd"));

        long timestamp = time2.getMillis() - time1.getMillis();

        out.println(timestamp);

        DateTimeZone.setDefault(DateTimeZone.UTC);
        DateTime time = new DateTime(timestamp);


        out.println(time);
    }

    public static void truncTime(){
        DateTime time = DateTime.now().withTime(0, 0 ,0 ,0);

        out.println(time);
    }

    public static void main(String[] args){
        DateTimeGet.timeInZone();
    }
}
