#include "Date_formatter.hpp"

struct tm
Date_formatter::date_localtime()
{
    time_t t = time(NULL);
    struct tm lt;
    localtime_r(&t, &lt);
    return lt;
}

/*
 * From a date string like <21-Mar-2015 15:13:29> returns only <hh:mm> if the
 * date indicates the same day that the current time, <day month> otherwise
 */
string
Date_formatter::format_date(string s)
{
    struct tm tm;
    strptime(s.c_str(), "%d-%b-%Y %H:%M:%S %z", &tm);

    time_t cur_time = time(NULL);
    if (cur_time == -1)  // if time fails, return an error message
        return "Error";

    struct tm now = *localtime(&cur_time);

    char fdate[7];

    if (now.tm_year == tm.tm_year
        && now.tm_mon == tm.tm_mon
        && now.tm_mday == tm.tm_mday) {
        strftime(fdate, sizeof(fdate), "%H:%M", &tm);
    } else {
        strftime(fdate, sizeof(fdate), "%d %b", &tm);
    }

    return fdate;
}

/*
 * Get current date formatted for a SMTP e-mail header
 * struct tm {
 *         int tm_sec;          // Seconds (0-60)
 *         int tm_min;          // Minutes (0-59)
 *         int tm_hour;         // Hours (0-23)
 *         int tm_mday;         // Day of the month (1-31)
 *         int tm_mon;          // Month (0-11)
 *         int tm_year;         // Year - 1900
 *         int tm_wday;         // Day of the week (0-6, Sunday = 0)
 *         int tm_yday;         // Day in the year (0-365, 1 Jan = 0)
 *         int tm_isdst;        // Daylight saving time
 *         long int tm_gmtoff;  // time zone offset in seconds
 *         const char *tm_zone; // name for the time zone
 * };
 * Output format (mandatory): Tue, 28 Apr 2015 21:06:40 +0200
 * Doc: http://tools.ietf.org/html/rfc2822#section-3.3 (specs for Date header)
 * FIXME: handle negative GMT
 */
string
Date_formatter::current_date()
{
    struct tm lt = date_localtime();
    char res[33];
    strftime(res, sizeof(res), "%Y-%m-%d, %H:%M:%S", &lt);
    return res;
}

#ifdef DATE_FORMATTER_DEBUG
int
main()
{
    Date_formatter* df {};

    // Test a > 24h date formatting
    string date("24-Apr-2015 16:05:09");
    cout << "Initial date: " << date << endl;
    cout << date << " => " << df->format_date(date) << endl;

    // Test a < 24h date formatting
    time_t t = time(NULL);
    struct tm lt;
    localtime_r(&t, &lt);
    char date2[33];
    strftime(date2, sizeof(date2), "%d-%b-%Y %H:%M:%S", &lt);
    cout << date2 << " => " << df->format_date(date2) << endl;

    // Print current date
    string cur_date = df->current_date();
    cout << "Current date: " << cur_date << endl;

    return 0;
}
#endif
