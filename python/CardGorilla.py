from bs4 import BeautifulSoup
from urllib.request import urlopen

url = "https://www.card-gorilla.com/card?cate=CRD"

html = urlopen(url)

bs = BeautifulSoup(html.read(), features="html.parser")
print(bs.prettify)

card_info = bs.find_all("div", "card-container")
print(card_info)