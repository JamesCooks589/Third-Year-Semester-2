exports.checkDate = (dateStr) => {
    const date = new Date(dateStr);
    const start = new Date('2023-09-09');
    const end = new Date('2023-09-22');
    return date > start && date <= end;
};

exports.checkName = (name) => {
    const regex = /[^a-zA-Z]/;
    return !regex.test(name);
};