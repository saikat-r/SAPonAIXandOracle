from pprint import pprint
import datetime
from datetime import datetime
from datetime import date

def main():
      d = date(2015, 05, 12)
      for attr in [ 'year', 'month', 'day' ]:
            print attr, ':', getattr(d, attr)

if __name__ == '__main__':
    main()