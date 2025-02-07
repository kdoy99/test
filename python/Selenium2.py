from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common import by
from webdriver_manager.chrome import ChromeDriverManager
import time

url = "https://www.card-gorilla.com/card?cate=CRD"
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))
driver.get(url)

sel = ".lst > li:nth-child(1) > div:nth-child(1)"
card_container = driver.find_element(by.By.CSS_SELECTOR, sel)

sel = "div.card_data > div.name > p > span"
name = card_container.find_elements(by.By.CSS_SELECTOR,sel)