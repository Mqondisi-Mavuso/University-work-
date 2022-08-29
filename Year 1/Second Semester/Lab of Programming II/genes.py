# online judge question from http://oj.csie.ndhu.edu.tw/problem/PR110-2Q6

class Person:
    def __init__(self):
        self.name = ""
        self.parent = ""
        self.status = -2

    def add_name(self, first):
        self.name = first

    def add_status(self, the_status):
        self.status = the_status

    def clear_person(self):
        self.name = ""
        self.parent = ""
        self.status = -1


def not_the_status(name):
    if name != "dominant" and name != "recessive" and name != "non-existent":
        return True
    else:
        return False


def get_status(str_status):
    if str_status == "dominant":
        return 1
    elif str_status == "recessive":
        return 0
    else:
        return -1


def find_parent_status(people_list, first_item_str, second_person):
    for j in range(len(people_list)):
        if people_list[j].name == first_item_str:
            # when it's their first time showing up
            if second_person.status < -1:
                return people_list[j].status        # they will have status of their parent
            else:
                return people_list[j].status + second_person.status
        else:
            continue
    return second_person.status


def print_status(given):
    if given < 0:
        return "non-existent"
    if given == 0:
        return "recessive"
    elif given > 0:
        return "dominant"


def does_name_exist(people_list, str_name):
    for i in range(len(people_list)):
        if people_list[i].name == str_name:
            return True
    return False


def get_parent_status(the_list_of_people, old_parent):
    for i in range(len(the_list_of_people)):
        if the_list_of_people[i].name == old_parent:
            return the_list_of_people[i].status


def get_person(people_list, person_name):
    for the_person in people_list:
        if the_person.name == person_name:
            return the_person
    return None


# --------------------------------------- Code implementation --------------------------------#
test_cases = int(input())
list_of_people = []

for index in range(test_cases):
    person = Person()                                # constructing the object
    items = list(map(str, input().split()))          # read and save to a list
    i = 0
    # when it's the person and their status
    if not_the_status(items[i]) and (i == 0 and not_the_status(items[i+1]) is False):
        st = get_status(items[i+1])              # returns status code (-1, 0 or 1)
        person.add_name(items[i])
        person.add_status(st)
        list_of_people.append(person)

    # it's the parent's name and their child
    elif not_the_status(items[i]) and (i == 0 and not_the_status(items[i+1])):
        # first time child showing up
        if does_name_exist(list_of_people, items[i+1]) is False:
            person.add_name(items[i+1])
            status = find_parent_status(list_of_people, items[i], person)
            person.add_status(status)
            list_of_people.append(person)

        else:
            # when the child is appearing for the second time have(both parents' status)
            child_str_name = items[i+1]
            child_object = get_person(people_list=list_of_people, person_name=child_str_name)
            s = get_parent_status(list_of_people, items[i])
            s += child_object.status
            child_object.add_status(s)

for the_people in list_of_people:
    print(f"{the_people.name} {print_status(the_people.status)}")
