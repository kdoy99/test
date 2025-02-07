from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common import by
from webdriver_manager.chrome import ChromeDriverManager

url = "https://www.card-gorilla.com/card?cate=CRD"
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))
driver.get(url)

sel = ".lst > li:nth-child(1) > div:nth-child(1)"
card_container = driver.find_element(by.By.CSS_SELECTOR, sel)

sel = "div.card_data > div.name > p > span"
name = card_container.find_elements(by.By.CSS_SELECTOR,sel)

for tag in name:
    print(tag.text)

sel = "div.card_data > div.sale > p"
sel_2 = "i"
sel_3 = "span > b"
sale = card_container.find_elements(by.By.CSS_SELECTOR, sel)

for tag in sale:
    benefit_att = tag.find_element(by.By.CSS_SELECTOR, sel_2)
    benefit_num = tag.find_element(by.By.CSS_SELECTOR, sel_3)
    print(benefit_att.text + " : " + benefit_num.text)