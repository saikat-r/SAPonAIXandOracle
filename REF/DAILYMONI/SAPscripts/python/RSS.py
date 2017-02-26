import os, re, sys, time, datetime, copy, calendar
from pattern.web import URL, extension, cache, plaintext, Newsfeed
 
class FeedsReader(object):
    def __init__(self):
 
        #For grouping to various category
        self.rss_sites_by_category_dict = {
                                            'SG':   [
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                      ],
                                            'World':[
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                        'https://www.facebook.com/feeds/notifications.php?id=586087848&viewer=586087848&key=AWifWb_C3nOAQ4ey&format=rss20',
                                                      ],
                                            }
        self.rss_sites = []
 
        ## num of feeds to parse_per_site
        self.num_feeds_parse_per_site = 100
 
        ## individual group storage of feeds.
        self.rss_results_dict = {} # dict with date as key
        self.rss_title_list = []
 
        ## full results set consist of category
        self.rss_results_dict_by_cat ={} # dict of dict
        self.rss_title_list_by_cat = {}  # dict of list
 
    def set_rss_sites(self, rss_site_urls):
        """ Set to self.rss_sites.
            Args:
                rss_site_urls (list): list of rss site url for getting feeds.
        """
        self.rss_sites = rss_site_urls
 
    def convert_date_str_to_date_key(self, date_str):
        """ Convert the date str given by twiiter [created_at] to date key in format YYYY-MM-DD.
            Args:
                date_str (str): date str in format given by twitter. 'Mon Sep 29 07:00:10 +0000 2014'
            Returns:
                (int): date key in format YYYYMMDD
        """
        date_list = date_str.split()
 
        month_dict = {v: '0'+str(k) for k,v in enumerate(calendar.month_abbr) if k <10}
        month_dict.update({v:str(k) for k,v in enumerate(calendar.month_abbr) if k >=10})
 
        return int(date_list[3] + month_dict[date_list[2]] + date_list[1])
 
    def parse_rss_sites(self):
        """ Function to parse the RSS sites.
            Results are stored in self.rss_results_dict with date as key.
        """
        self.rss_results_dict = {}
        self.rss_title_list = []
 
        cache.clear()
 
        for rss_site_url in self.rss_sites:
            print "processing: ", rss_site_url
            for result in Newsfeed().search(rss_site_url)[:self.num_feeds_parse_per_site]:
                date_key = self.convert_date_str_to_date_key(result.date)
                self.rss_title_list.append(result.title)
                if self.rss_results_dict.has_key(date_key):
                    self.rss_results_dict[date_key].append([result.title,  plaintext(result.text)])
                else:
                    self.rss_results_dict[date_key] = [[result.title,  plaintext(result.text)]]
        print 'done'
 
    def parse_rss_sites_by_cat(self):
        """ Iterate over the list of categories and parse the list of rss sites.
        """
        self.rss_results_dict_by_cat ={} # dict of dict
        self.rss_title_list_by_cat = {}  # dict of list
 
        for cat in self.rss_sites_by_category_dict:
            print 'Processing Category: ', cat
            self.set_rss_sites(self.rss_sites_by_category_dict[cat])
            self.parse_rss_sites()
            self.rss_results_dict_by_cat[cat] = self.rss_results_dict
            self.rss_title_list_by_cat[cat] = self.rss_title_list
 
    def set_last_desired_date(self, num_days = 0):
        """ Return the last date in which the results will be displayed.
            It is set to be the current date - num of days as set by users.
            Affect only self.print_feeds function.
            Kwargs:
                num_days (int): num of days prior to the current date.
                Setting to 0 will only retrieve the current date
            Returns:
                (int): datekey as yyyyymmdd.
        """
        last_eff_date_list = list((datetime.date.today() - datetime.timedelta(num_days)).timetuple()[0:3])
 
        if len(str(last_eff_date_list[1])) == 1:
            last_eff_date_list[1] = '0' + str(last_eff_date_list[1])
 
        return int(str(last_eff_date_list[0]) + last_eff_date_list[1] + str(last_eff_date_list[2]))
 
    def print_feeds(self, rss_results_dict):
        """ Print the RSS data results. Required the self.rss_results_dict.
            Args:
                rss_results_dict (dict): dict containing date as key and title, desc as value.
        """
        for n in rss_results_dict.keys():
            print 'Results of date: ', n
            dataset = rss_results_dict[n]
            if int(n) >= self.set_last_desired_date():
                print '===='*10
                for title,desc in dataset:
                    print title
                    print desc
                    print '--'*5
                    print
 
    def print_feeds_for_all_cat(self):
        """ Print feeds for all the category specified by the self.rss_results_dict_by_cat
 
        """
        for cat in self.rss_results_dict_by_cat:
            print 'Printing Category: ', cat
            self.print_feeds(self.rss_results_dict_by_cat[cat])
            print
            print "####"*18
 
if __name__ == '__main__':
        f = FeedsReader()
        f.parse_rss_sites_by_cat()
        print '=='*19
        f.print_feeds_for_all_cat()
