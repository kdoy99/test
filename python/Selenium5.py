from selenium import webdriver
from selenium.webdriver.chrome.service import Service
from selenium.webdriver.common import by
from webdriver_manager.chrome import ChromeDriverManager
from selenium.webdriver.support.wait import WebDriverWait
from selenium import common
from selenium.webdriver.common.action_chains import ActionChains

import time
import random
import pandas as pd
import os

from Selenium import card_container
from Selenium3 import benefit_att, benefit_num

url = "https://www.card-gorilla.com/card?cate=CRD"
driver = webdriver.Chrome(service=Service(ChromeDriverManager().install()))
driver.get(url)

df = pd.DataFrame({"카드명": [], "카드회사": [], "혜택1": [], "혜택2": [], "혜택3": []})

sel = "#q-app > section > div.card > section > div > div.card_list > div.ftr > a.lst_more"
for i in range(3):
    try:
        more_btn = WebDriverWait(driver, timeout=10).until(
            lambda d: d.find_element(by.By.CSS_SELECTOR, sel)
        )
        driver.execute_script("arguments[0].click();", more_btn)
        time.sleep(round(random.random() * 2, 2) + 2)
    except common.exceptions.TimeoutException as e:
        break
sel = "#q-app > section > div.card > section > div > div.card_list > ul > li"
cards = driver.find_elements(by.By.CSS_SELECTOR, sel)

actions = ActionChains(driver)
for card in cards:
    tmp_list = []
    sel = "div > div.card_data > div.benefit > a"
    new_page_btn = card.find_element(by.By.CSS_SELECTOR, sel)
    driver.execute_script(f"window.open('{new_page_btn.get_attribute("href")}');")
    driver.switch_to.window(driver.window_handles[1])
    sel = "#q-app > section > div.card_detail.fr-view > section > div > article.cmd_con.benefit > div.lst.bene_"
    benefits = driver.find_elements(by.By.CSS_SELECTOR, sel)

    for benefit in benefits[:-1]:
        actions.move_to_element(benefit).perform()
        driver.execute_script("window.scrollBy(0, 100);")
        actions.click(benefit).perform()
        sel = "dd > div.in_box > p > strong"
        try:
            datas = WebDriverWait(benefit, timeout=5).until(
                lambda d: d.find_elements(by.By.CSS_SELECTOR, sel))[:-1]
        except common.exceptions.TimeoutException as e:
            continue

        for data in datas:
            print(data.text)

        time.sleep(round(random.random() * 1, 2) + 1)
    time.sleep(round(random.random() * 2, 2) + 2)

    driver.close()
    driver.switch_to.window(driver.window_handles[0])